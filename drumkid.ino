#include <ADC.h>
#include <MozziGuts.h>
#include <Sample.h>
#include <EventDelay.h>

#define CONTROL_RATE 64

const int SEQUENCE_LENGTH = 16;

// channel defs
const int NUM_CHANNELS = 6;
const int MAX_CHANNEL_SOUNDS = 8;
const int KICK = 0;
const int SNARE = 1;
const int HAT = 2;
const int TOM_LOW = 3;
const int TOM_MID = 4;
const int TOM_HIGH = 5;
// etc...

// select modes
const int BEAT_SELECT = 0;
const int CHANNEL_SELECT = 1;
const int SOUND_SELECT = 2;
const int SAVE_SELECT = 3;

// selection
int selectMode = BEAT_SELECT;
int selectedBeat = 0;
int selectedChannel = 0;

// timing
EventDelay stepDelay;
EventDelay halfStepDelay;
int stepDelayPeriod = 100;
int currentStep = 0;

// output
long out;

// control
bool playing = true;
int zoom = 0;
int hyperactivity = 0;
float pitch = 1.0;
bool hitInputReady = true;

#include "SampleDefs.h";

class Channel {
  public:
    Channel();
    int next();
    void startHit(int velocity);
    byte getSoundIndex();
    void setSoundIndex(byte soundIndex);
    byte getNumSounds();
    void defineSounds(byte sounds[], byte numSounds);
    void setPitch(float pitch);
    void setVolume(int vol);
    void setSequence(bool sequence[SEQUENCE_LENGTH]);
  private:
    byte _sounds[MAX_CHANNEL_SOUNDS];
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
  _out = sampleNext(_sound);
  return _out * _vel * _vol / 128;
}

void Channel::startHit(int velocity) {
  _vel = velocity;
  sampleStart(_sound);
}

void Channel::setPitch(float pitch) {
  samplePitch(_sound);
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

class Sequence {
  public:
    Sequence();
    bool sc[NUM_CHANNELS][SEQUENCE_LENGTH]; // channels
    void init(int channel, bool sequence[]);
    void setHit(bool onOff);

  private:
    
};

Sequence::Sequence() {
  
}

void Sequence::init(int channel, bool sequence[]) {
  for(int i = 0; i < SEQUENCE_LENGTH; i ++) {
    sc[channel][i] = sequence[i];
  }
}

void Sequence::setHit(bool onOff) {
  byte newHitStep = currentStep - 1;
  
  if(halfStepDelay.ready()) newHitStep ++;
  else c[selectedChannel].startHit(100);
  sc[selectedChannel][newHitStep % SEQUENCE_LENGTH] = onOff;
}

Sequence s[100];

void setup() {
  Serial.begin(9600);
  delay(500);
  pinMode(2, INPUT);
  pinMode(13, OUTPUT);
  randomSeed(analogRead(0));
  initSequences();
  startMozzi(CONTROL_RATE);
  
  c[KICK].defineSounds(soundList_kick,soundListNum_kick);
  c[HAT].defineSounds(soundList_hat,soundListNum_hat);
  c[SNARE].defineSounds(soundList_snare,soundListNum_snare);
  
  stepDelay.set(stepDelayPeriod);
  halfStepDelay.set(stepDelayPeriod / 2);
}

void loop() {
  audioHook();
}

void updateControl(){
  if(digitalRead(2)) {
    if(hitInputReady) s[selectedBeat].setHit(true);
    hitInputReady = false;
  } else {
    hitInputReady = true;
  }
  checkSerialCommand();
  if(stepDelay.ready() && playing) {
    //digitalWrite(13, currentStep % 4 == 0);
    int r; // random number
    int v; // velocity
    for(int i = 0; i < NUM_CHANNELS; i ++) {
      v = 0;
      r = random(100);
      if(s[selectedBeat].sc[i][currentStep]) {
        v = 100;
      } else if(r < hyperactivity) {
        v = 100;
      }
      c[i].setPitch(pitch);
      if(v > 0) c[i].startHit(v);
    }
    stepDelay.set(stepDelayPeriod);
    stepDelay.start();
    halfStepDelay.set(stepDelayPeriod / 2);
    halfStepDelay.start();
    currentStep ++;
    currentStep = currentStep % SEQUENCE_LENGTH;
  }
}

int updateAudio(){
  out = c[KICK].next() + c[HAT].next() + c[SNARE].next();
  out = out >> 3;
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
    else if(command == "h") s[selectedBeat].setHit(true);
    else if(command == "tempo") {
      //tempo = param.toInt();
    } else if(command == "pitch") {
      pitch = param.toFloat();
    } else if(command == "hyper") {
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
  s[0].init(HAT, a2);
  bool a3[] = {0,0,0,0,1,0,0,0,0,0,0,0,1,0,0,0,};
  s[0].init(SNARE, a3);

  bool b1[] = {1,0,0,0,0,0,1,1,0,0,0,1,0,0,0,1,};
  s[1].init(KICK, b1);
  bool b2[] = {0,0,1,0,0,0,1,0,0,0,1,0,0,1,1,0,};
  s[1].init(HAT, b2);
  bool b3[] = {1,1,0,0,1,0,0,0,0,0,0,0,1,1,0,0,};
  s[1].init(SNARE, b3);

  bool c2[] = {1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,};
  s[2].init(HAT, c2);
}

