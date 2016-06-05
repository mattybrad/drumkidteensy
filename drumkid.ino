#include <ADC.h>
#include <MozziGuts.h>
#include <Sample.h>
#include <EventDelay.h>
#include <samples/mattdrums/closedhat.h>
#include <samples/mattdrums/snare.h>
#include <samples/mattdrums/kick.h>

#define CONTROL_RATE 64

Sample <closedhat_NUM_CELLS, AUDIO_RATE> s_hat_808(closedhat_DATA);
Sample <snare_NUM_CELLS, AUDIO_RATE> s_snare_niko(snare_DATA);
Sample <kick_NUM_CELLS, AUDIO_RATE> s_kick_808(kick_DATA);

const int SEQUENCE_LENGTH = 16;

// channel defs
const int NUM_CHANNELS = 6;
const int KICK = 0;
const int SNARE = 1;
const int HAT_CLOSED = 2;
const int TOM_LOW = 3;
const int TOM_MID = 4;
const int TIM_HIGH = 5;
// etc...

// sound defs
const int KICK_808 = 0;
const int KICK_SOFT = 1;
const int SNARE_808 = 2;
const int SNARE_NIKO = 3;
const int HAT_808 = 4;
// etc...

// timing
EventDelay stepDelay;
int stepDelayPeriod = 100;

// output
long out;

class Sequence {
  public:
    Sequence();
    bool c[NUM_CHANNELS][SEQUENCE_LENGTH]; // channels
    void init(int channel, bool *sequence);

  private:
    
};

Sequence::Sequence() {
  
}

void Sequence::init(int channel, bool *sequence) {
  for(int i = 0; i < SEQUENCE_LENGTH; i ++) {
    c[channel][i] = sequence[i];
  }
}

class Channel {
  public:
    Channel();
    int next();
    void start(int velocity);
    void setSound(int sound);
    void setPitch(float pitch);
    void setVolume(int vol);
    void setSequence(bool sequence[SEQUENCE_LENGTH]);
  private:
    bool _sequence[SEQUENCE_LENGTH];
    int _sound = HAT_808;
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
  }
}

void Channel::setVolume(int vol) {
  _vol = constrain(vol, 0, 127);
}

void Channel::setSound(int sound) {
  // check here whether sound is allowed for this channel
  // or at least check sound not being used twice
  _sound = sound;
  setPitch(1.0);
}

Channel c[NUM_CHANNELS];
Sequence s[2];

// control
bool playing = true;
int activeSequence = 0;
int zoom = 0;
int hyperactivity = 0;
int pitch = 0;

void setup() {
  randomSeed(analogRead(0));
  initSequences();
  Serial.begin(9600);
  startMozzi(CONTROL_RATE);
  c[KICK].setSound(KICK_808);
  c[HAT_CLOSED].setSound(HAT_808);
  c[SNARE].setSound(SNARE_NIKO);
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
      if(s[activeSequence].c[i][counter % SEQUENCE_LENGTH]) {
        v = 100;
      } else if(r < hyperactivity) {
        v = 100;
      }
      if(v > 0) c[i].start(v);
    }
    stepDelay.set(stepDelayPeriod);
    stepDelay.start();
    counter ++;
  }
}

int updateAudio(){
  out = c[KICK].next() + c[HAT_CLOSED].next() + c[SNARE].next();
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
    if(command == "stop") playing = false;
    else if(command == "start") playing = true;
    else if(command == "t") {
      //tempo = param.toInt();
    } else if(command == "p") {
      //setPitch(param.toFloat());
    } else if(command == "h") {
      hyperactivity = param.toInt();
    }
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

