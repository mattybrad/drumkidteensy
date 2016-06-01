#include <ADC.h>
#include <MozziGuts.h>
#include <Sample.h> // Sample template
#include <samples/mattdrums/kick.h>
#include <samples/mattdrums/snare.h>
#include <samples/mattdrums/closedhat.h>
#include <samples/mattdrums/tommid.h>
#include <EventDelay.h>

#define CONTROL_RATE 64

Sample <snare_NUM_CELLS, AUDIO_RATE> smSnare(snare_DATA);
Sample <closedhat_NUM_CELLS, AUDIO_RATE> smHat(closedhat_DATA);
Sample <kick_NUM_CELLS, AUDIO_RATE> smKick(kick_DATA);
Sample <tommid_NUM_CELLS, AUDIO_RATE> smTom(tommid_DATA);

EventDelay stepDelay;
int stepNum = 0;
int stepsTotal = 16;
long out;

// pins
const int START_PIN = 2;
const int LED_PIN = 13;

// control
bool playing = true;
bool playButtonPrevState = false;

class Beat {
  public:
    Beat();
    bool hat[16] = {0,0,1,1,1,0,1,0,1,0,1,1,1,1,0,1,};
    bool snare[16] = {0,0,0,0,1,1,0,0,0,0,0,0,1,0,0,1,};
    bool kick[16] = {1,0,0,0,1,0,0,0,1,0,0,0,1,0,1,0,};
    bool tom[16] = {0,0,1,0,0,0,0,1,0,0,1,0,0,0,0,1,};
  private:
    int x;
};

Beat::Beat() {
  
}

Beat b;

void setup() {
  pinMode(LED_PIN, OUTPUT);
  pinMode(START_PIN, INPUT);
  startMozzi(CONTROL_RATE);
  smSnare.setFreq((float) snare_SAMPLERATE / (float) snare_NUM_CELLS);
  smHat.setFreq((float) closedhat_SAMPLERATE / (float) closedhat_NUM_CELLS);
  smKick.setFreq((float) kick_SAMPLERATE / (float) kick_NUM_CELLS);
  smTom.setFreq((float) tommid_SAMPLERATE / (float) tommid_NUM_CELLS);
  Serial.begin(9600);
  stepDelay.set(110);
  resetSamples();
}

void resetSamples() {
  // probably not the most efficient way of doing this!
  while(smSnare.isPlaying()) smSnare.next();
  while(smHat.isPlaying()) smHat.next();
  while(smKick.isPlaying()) smKick.next();
  while(smTom.isPlaying()) smTom.next();
}

void updateControl(){
  if(!playButtonPrevState && digitalRead(START_PIN)) {
    playing = !playing;
    if(!playing) {
      stepNum = 0;
      stepDelay.set(0);
      resetSamples();
    }
  }
  playButtonPrevState = digitalRead(START_PIN);
  //smSnare.setFreq(((float) map(mozziAnalogRead(0),0,1023,200,1) / (float) 100) * (float) snare_SAMPLERATE / (float) snare_NUM_CELLS);
  //smHat.setFreq(((float) map(mozziAnalogRead(0),0,1023,200,1) / (float) 100) * (float) closedhat_SAMPLERATE / (float) closedhat_NUM_CELLS);
  //smKick.setFreq(((float) map(mozziAnalogRead(0),0,1023,200,1) / (float) 100) * (float) kick_SAMPLERATE / (float) kick_NUM_CELLS);
  //smTom.setFreq(((float) map(mozziAnalogRead(0),0,1023,200,1) / (float) 100) * (float) tommid_SAMPLERATE / (float) tommid_NUM_CELLS);
  if(playing && stepDelay.ready()){
    if(b.hat[stepNum]) smHat.start();
    if(b.snare[stepNum]) smSnare.start();
    if(b.kick[stepNum]) smKick.start();
    if(b.tom[stepNum]) smTom.start();
    //stepDelay.set(map(mozziAnalogRead(0),0,1023,50,250));
    stepDelay.start();
    stepNum ++;
    stepNum = stepNum % stepsTotal;
  }
}

int updateAudio(){
  if(playing) {
    //return (int) (smSnare.next() >> 1) + (smHat.next() >> 2) + (smKick.next() >> 1);
    out = 0;
    out += smSnare.next();
    out += smKick.next() >> 1;
    out += smHat.next() >> 2;
    out += smTom.next() >> 1;
    out = out << 4;
    return out;
  } else {
    return 0;
  }
}

void loop() {
  audioHook();
}
