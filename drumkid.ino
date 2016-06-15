#include <ADC.h>
#include <MozziGuts.h>
#include <Sample.h>
#include <EventDelay.h>
#include "DisplayBytes.h";

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

// pins
int HIT_PIN = 2;
int INC_PIN = 3;
int DEC_PIN = 4;
int BEAT_PIN = 5;
int CHANNEL_PIN = 6;
int SOUND_PIN = 7;
//Pin connected to ST_CP of 74HC595
int DISPLAY_LATCH_PIN = 10;
//Pin connected to SH_CP of 74HC595
int DISPLAY_CLOCK_PIN = 12;
////Pin connected to DS of 74HC595
int DISPLAY_DATA_PIN = 11;

// control
bool playing = true;
int zoom = 0;
int hyperactivity = 0;
float pitch = 1.0;
bool hitInputReady = true;
bool incReady = true;
bool decReady = true;

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
  pinMode(DISPLAY_LATCH_PIN, OUTPUT);
  updateDisplay(0);
  Serial.begin(9600);
  delay(500);
  pinMode(HIT_PIN, INPUT);
  pinMode(INC_PIN, INPUT);
  pinMode(DEC_PIN, INPUT);
  pinMode(BEAT_PIN, INPUT);
  pinMode(CHANNEL_PIN, INPUT);
  pinMode(SOUND_PIN, INPUT);
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
  if(digitalRead(HIT_PIN)) {
    if(hitInputReady) s[selectedBeat].setHit(true);
    hitInputReady = false;
  } else {
    hitInputReady = true;
  }
  if(digitalRead(BEAT_PIN)) selectMode = BEAT_SELECT;
  if(digitalRead(CHANNEL_PIN)) selectMode = CHANNEL_SELECT;
  if(digitalRead(SOUND_PIN)) selectMode = SOUND_SELECT;
  if(digitalRead(INC_PIN)) {
    if(incReady) handleIncDec(1);
    incReady = false;
  } else {
    incReady = true;
  }
  if(digitalRead(DEC_PIN)) {
    if(decReady) handleIncDec(-1);
    decReady = false;
  } else {
    decReady = true;
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
    updateDisplay(selectedBeat);
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

void updateDisplay(int num) {
  num = num % 100;
  digitalWrite(DISPLAY_LATCH_PIN, 0);
  shiftOut(DISPLAY_DATA_PIN, DISPLAY_CLOCK_PIN, numbers2[num % 10]);
  shiftOut(DISPLAY_DATA_PIN, DISPLAY_CLOCK_PIN, numbers1[num / 10]);
  digitalWrite(DISPLAY_LATCH_PIN, 1);
}

// copied off internet
void shiftOut(int myDataPin, int myClockPin, byte myDataOut) {
  // This shifts 8 bits out MSB first, 
  //on the rising edge of the clock,
  //clock idles low

  //internal function setup
  int i=0;
  int pinState;
  pinMode(myClockPin, OUTPUT);
  pinMode(myDataPin, OUTPUT);

 //clear everything out just in case to
 //prepare shift register for bit shifting
  digitalWrite(myDataPin, 0);
  digitalWrite(myClockPin, 0);

  //for each bit in the byte myDataOut�
  //NOTICE THAT WE ARE COUNTING DOWN in our for loop
  //This means that %00000001 or "1" will go through such
  //that it will be pin Q0 that lights. 
  for (i=7; i>=0; i--)  {
    digitalWrite(myClockPin, 0);

    //if the value passed to myDataOut and a bitmask result 
    // true then... so if we are at i=6 and our value is
    // %11010100 it would the code compares it to %01000000 
    // and proceeds to set pinState to 1.
    if ( myDataOut & (1<<i) ) {
      pinState= 1;
    }
    else {  
      pinState= 0;
    }

    //Sets the pin to HIGH or LOW depending on pinState
    digitalWrite(myDataPin, pinState);
    //register shifts bits on upstroke of clock pin  
    digitalWrite(myClockPin, 1);
    //zero the data pin after shift to prevent bleed through
    digitalWrite(myDataPin, 0);
  }

  //stop shifting
  digitalWrite(myClockPin, 0);
}
