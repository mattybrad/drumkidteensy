#include <ADC.h>
#include <MozziGuts.h>
#include <Sample.h>
#include <EventDelay.h>
#include <samples/mattdrums/closedhat.h>
#include <samples/mattdrums/snare.h>
#include <samples/mattdrums/kick.h>
#include <samples/mattdrums/clap.h>

#define CONTROL_RATE 64

Sample <closedhat_NUM_CELLS, AUDIO_RATE> s_hat_808(closedhat_DATA);
Sample <snare_NUM_CELLS, AUDIO_RATE> s_snare_niko(snare_DATA);
Sample <kick_NUM_CELLS, AUDIO_RATE> s_kick_808(kick_DATA);
Sample <clap_NUM_CELLS, AUDIO_RATE> s_clap(clap_DATA);

const int SEQUENCE_LENGTH = 16;

// channel defs
const int NUM_CHANNELS = 6;
const int MAX_CHANNEL_SOUNDS = 8;
const int KICK = 0;
const int SNARE = 1;
const int HAT_CLOSED = 2;
const int TOM_LOW = 3;
const int TOM_MID = 4;
const int TOM_HIGH = 5;
// etc...

// sound defs
const byte KICK_808 = 0;
const byte KICK_NOISE = 1;
const byte SNARE_808 = 2;
const byte SNARE_NIKO = 3;
const byte HAT_808 = 4;
const byte CLAP = 5;
// etc...

// timing
EventDelay stepDelay;
int stepDelayPeriod = 100;

// output
long out;

// control
bool playing = true;
int zoom = 0;
int hyperactivity = 0;
float pitch = 1.0;

class Sequence {
  public:
    Sequence();
    bool c[NUM_CHANNELS][SEQUENCE_LENGTH]; // channels
    void init(int channel, bool sequence[]);

  private:
    
};

Sequence::Sequence() {
  
}

void Sequence::init(int channel, bool sequence[]) {
  for(int i = 0; i < SEQUENCE_LENGTH; i ++) {
    c[channel][i] = sequence[i];
  }
}

class Channel {
  public:
    Channel();
    int next();
    void start(int velocity);
    byte getSoundIndex();
    void setSoundIndex(byte soundIndex);
    byte getNumSounds();
    void defineSounds(byte sounds[], byte numSounds);
    void setPitch(float pitch);
    void setVolume(int vol);
    void setSequence(bool sequence[SEQUENCE_LENGTH]);
  private:
    byte _sounds[MAX_CHANNEL_SOUNDS];
    bool _sequence[SEQUENCE_LENGTH];
    byte _soundIndex = 0;
    byte _numSounds = 0;
    int _sound = 0;
    int _vol = 63;
    int _vel = 0;
    int _out;
};

Channel::Channel() {
  
}

int Channel::next() {
  switch(_sound) {
    case HAT_808:
    _out = s_hat_808.next();
    break;

    case SNARE_NIKO:
    _out = s_snare_niko.next();
    break;

    case KICK_808:
    _out = s_kick_808.next();
    break;

    case CLAP:
    _out = s_clap.next();
    break;

    default:
    _out = 0;
  }
  return _out * _vel * _vol / 128;
}

void Channel::start(int velocity) {
  _vel = velocity;
  switch(_sound) {
    case HAT_808:
    s_hat_808.start();
    break;

    case SNARE_NIKO:
    s_snare_niko.start();
    break;

    case KICK_808:
    s_kick_808.start();
    break;

    case CLAP:
    s_clap.start();
    break;
  }
}

void Channel::setPitch(float pitch) {
  switch(_sound) {
    case HAT_808:
    s_hat_808.setFreq(pitch * (float) closedhat_SAMPLERATE / (float) closedhat_NUM_CELLS);
    break;

    case SNARE_NIKO:
    s_snare_niko.setFreq(pitch * (float) snare_SAMPLERATE / (float) snare_NUM_CELLS);
    break;

    case KICK_808:
    s_kick_808.setFreq(pitch * (float) kick_SAMPLERATE / (float) kick_NUM_CELLS);
    break;

    case CLAP:
    s_clap.setFreq(pitch * (float) clap_SAMPLERATE / (float) clap_NUM_CELLS);
    break;
  }
}

void Channel::setVolume(int vol) {
  _vol = constrain(vol, 0, 127);
}

void Channel::defineSounds(byte sounds[], byte numSounds) {
  _numSounds = numSounds;
  for(byte i = 0; i < _numSounds; i ++) {
    _sounds[i] = sounds[i];
  }
  setSoundIndex(0);
}

void Channel::setSoundIndex(byte soundIndex) {
  _soundIndex = soundIndex;
  _sound = _sounds[_soundIndex];
  setPitch(pitch);
}

byte Channel::getSoundIndex() {
  return _soundIndex;
}

byte Channel::getNumSounds() {
  return _numSounds;
}

Channel c[NUM_CHANNELS];
Sequence s[100];

// select modes
const int BEAT_SELECT = 0;
const int CHANNEL_SELECT = 1;
const int SOUND_SELECT = 2;
const int SAVE_SELECT = 3;

// selection
int selectMode = BEAT_SELECT;
int selectedBeat = 0;
int selectedChannel = 0;

void setup() {
  Serial.begin(9600);
  delay(1000);
  randomSeed(analogRead(0));
  initSequences();
  startMozzi(CONTROL_RATE);
  
  byte kickSounds[] = {KICK_808};
  c[KICK].defineSounds(kickSounds,1);
  byte hatSounds[] = {HAT_808};
  c[HAT_CLOSED].defineSounds(hatSounds,1);
  byte snareSounds[] = {SNARE_NIKO,CLAP};
  c[SNARE].defineSounds(snareSounds,2);
  
  stepDelay.set(stepDelayPeriod);
}

void loop() {
  audioHook();
}

int counter = 0;
void updateControl(){
  checkSerialCommand();
  if(stepDelay.ready() && playing) {
    int r; // random number
    int v; // velocity
    for(int i = 0; i < NUM_CHANNELS; i ++) {
      v = 0;
      r = random(100);
      if(s[selectedBeat].c[i][counter % SEQUENCE_LENGTH]) {
        v = 100;
      } else if(r < hyperactivity) {
        v = 100;
      }
      c[i].setPitch(pitch);
      if(v > 0) c[i].start(v);
    }
    stepDelay.set(stepDelayPeriod);
    stepDelay.start();
    counter ++;
  }
}

int updateAudio(){
  out = c[KICK].next() + c[HAT_CLOSED].next() + c[SNARE].next();
  out = out >> 2;
  return out;
}

void checkSerialCommand() {
  String command = "";
  String param = "";
  bool commandFound = false;
  bool spaceFound = false;
  char thisChar;
  while(Serial.available()) {
    thisChar = (char) Serial.read();
    if(!spaceFound && thisChar == ' ') spaceFound = true;
    else if(spaceFound) param += thisChar;
    else command += thisChar;
    commandFound = true;
  }
  if(commandFound) {
    if(command == "+") handleIncDec(1);
    else if(command == "-") handleIncDec(-1);
    else if(command == "beat") selectMode = BEAT_SELECT;
    else if(command == "channel") selectMode = CHANNEL_SELECT;
    else if(command == "sound") selectMode = SOUND_SELECT;
    else if(command == "stop") playing = false;
    else if(command == "start") playing = true;
    else if(command == "t") {
      //tempo = param.toInt();
    } else if(command == "p") {
      pitch = param.toFloat();
    } else if(command == "h") {
      hyperactivity = param.toInt();
    }
  }
}

void handleIncDec(int delta) {
  switch(selectMode) {
    case BEAT_SELECT:
    selectedBeat += delta;
    selectedBeat = constrain(selectedBeat, 0, 99);
    Serial.println(selectedBeat);
    break;

    case CHANNEL_SELECT:
    selectedChannel += delta;
    selectedChannel = constrain(selectedChannel, 0, NUM_CHANNELS - 1);
    Serial.println(selectedChannel);
    break;

    case SOUND_SELECT:
    int currentSoundIndex = c[selectedChannel].getSoundIndex();
    byte numSounds = c[selectedChannel].getNumSounds();
    currentSoundIndex += delta;
    currentSoundIndex = constrain(currentSoundIndex, 0, numSounds - 1);
    c[selectedChannel].setSoundIndex(currentSoundIndex);
    Serial.println(c[selectedChannel].getSoundIndex());
    break;
  }
}

void initSequences() {
  // not the prettiest way of doing this but it's fine for now so shut up
  bool a1[] = {1,0,0,0,1,0,0,0,1,0,0,0,1,0,0,0,};
  s[0].init(KICK, a1);
  bool a2[] = {1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,};
  s[0].init(HAT_CLOSED, a2);
  bool a3[] = {0,0,0,0,1,0,0,0,0,0,0,0,1,0,0,0,};
  s[0].init(SNARE, a3);

  bool b1[] = {1,0,0,0,0,0,1,1,0,0,0,1,0,0,0,1,};
  s[1].init(KICK, b1);
  bool b2[] = {0,0,1,0,0,0,1,0,0,0,1,0,0,1,1,0,};
  s[1].init(HAT_CLOSED, b2);
  bool b3[] = {1,1,0,0,1,0,0,0,0,0,0,0,1,1,0,0,};
  s[1].init(SNARE, b3);
}

