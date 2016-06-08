#include <samples/mattdrums/hat808.h>
#include <samples/mattdrums/hatbeep.h>
#include <samples/mattdrums/kick808.h>
#include <samples/mattdrums/kickbeep.h>
#include <samples/mattdrums/kicknoise.h>
#include <samples/mattdrums/claves808.h>
#include <samples/mattdrums/rim808.h>
#include <samples/mattdrums/shaker.h>
#include <samples/mattdrums/clap808.h>
#include <samples/mattdrums/snarebeep.h>
#include <samples/mattdrums/snareniko.h>
#include <samples/mattdrums/snarenoise.h>
#include <samples/mattdrums/tomhigh808.h>
#include <samples/mattdrums/tommid808.h>
#include <samples/mattdrums/tomlow808.h>

Sample <hat808_NUM_CELLS, AUDIO_RATE> s_hat808(hat808_DATA);
Sample <hatbeep_NUM_CELLS, AUDIO_RATE> s_hatbeep(hatbeep_DATA);
Sample <kick808_NUM_CELLS, AUDIO_RATE> s_kick808(kick808_DATA);
Sample <kickbeep_NUM_CELLS, AUDIO_RATE> s_kickbeep(kickbeep_DATA);
Sample <kicknoise_NUM_CELLS, AUDIO_RATE> s_kicknoise(kicknoise_DATA);
Sample <claves808_NUM_CELLS, AUDIO_RATE> s_claves808(claves808_DATA);
Sample <rim808_NUM_CELLS, AUDIO_RATE> s_rim808(rim808_DATA);
Sample <shaker_NUM_CELLS, AUDIO_RATE> s_shaker(shaker_DATA);
Sample <clap808_NUM_CELLS, AUDIO_RATE> s_clap808(clap808_DATA);
Sample <snarebeep_NUM_CELLS, AUDIO_RATE> s_snarebeep(snarebeep_DATA);
Sample <snareniko_NUM_CELLS, AUDIO_RATE> s_snareniko(snareniko_DATA);
Sample <snarenoise_NUM_CELLS, AUDIO_RATE> s_snarenoise(snarenoise_DATA);
Sample <tomhigh808_NUM_CELLS, AUDIO_RATE> s_tomhigh808(tomhigh808_DATA);
Sample <tommid808_NUM_CELLS, AUDIO_RATE> s_tommid808(tommid808_DATA);
Sample <tomlow808_NUM_CELLS, AUDIO_RATE> s_tomlow808(tomlow808_DATA);

const byte S_HAT808 = 0;
const byte S_HATBEEP = 1;
const byte S_KICK808 = 2;
const byte S_KICKBEEP = 3;
const byte S_KICKNOISE = 4;
const byte S_CLAVES808 = 5;
const byte S_RIM808 = 6;
const byte S_SHAKER = 7;
const byte S_CLAP808 = 8;
const byte S_SNAREBEEP = 9;
const byte S_SNARENIKO = 10;
const byte S_SNARENOISE = 11;
const byte S_TOMHIGH808 = 12;
const byte S_TOMMID808 = 13;
const byte S_TOMLOW808 = 14;

byte soundList_hat[] = {S_HAT808,S_HATBEEP,};
byte soundListNum_hat = 2;
byte soundList_kick[] = {S_KICK808,S_KICKBEEP,S_KICKNOISE,};
byte soundListNum_kick = 3;
byte soundList_percussion[] = {S_CLAVES808,S_RIM808,S_SHAKER,};
byte soundListNum_percussion = 3;
byte soundList_snare[] = {S_CLAP808,S_SNAREBEEP,S_SNARENIKO,S_SNARENOISE,};
byte soundListNum_snare = 4;
byte soundList_tomhigh[] = {S_TOMHIGH808,S_TOMMID808,};
byte soundListNum_tomhigh = 2;
byte soundList_tomlow[] = {S_TOMLOW808,};
byte soundListNum_tomlow = 1;

int sampleNext(int sound) {
int nextOut;
switch(sound) {
case S_HAT808:
nextOut = s_hat808.next();
break;

case S_HATBEEP:
nextOut = s_hatbeep.next();
break;

case S_KICK808:
nextOut = s_kick808.next();
break;

case S_KICKBEEP:
nextOut = s_kickbeep.next();
break;

case S_KICKNOISE:
nextOut = s_kicknoise.next();
break;

case S_CLAVES808:
nextOut = s_claves808.next();
break;

case S_RIM808:
nextOut = s_rim808.next();
break;

case S_SHAKER:
nextOut = s_shaker.next();
break;

case S_CLAP808:
nextOut = s_clap808.next();
break;

case S_SNAREBEEP:
nextOut = s_snarebeep.next();
break;

case S_SNARENIKO:
nextOut = s_snareniko.next();
break;

case S_SNARENOISE:
nextOut = s_snarenoise.next();
break;

case S_TOMHIGH808:
nextOut = s_tomhigh808.next();
break;

case S_TOMMID808:
nextOut = s_tommid808.next();
break;

case S_TOMLOW808:
nextOut = s_tomlow808.next();
break;

default:
nextOut=0;
}
return nextOut;
}

void sampleStart(int sound) {
switch(sound) {
case S_HAT808:
s_hat808.start();
break;

case S_HATBEEP:
s_hatbeep.start();
break;

case S_KICK808:
s_kick808.start();
break;

case S_KICKBEEP:
s_kickbeep.start();
break;

case S_KICKNOISE:
s_kicknoise.start();
break;

case S_CLAVES808:
s_claves808.start();
break;

case S_RIM808:
s_rim808.start();
break;

case S_SHAKER:
s_shaker.start();
break;

case S_CLAP808:
s_clap808.start();
break;

case S_SNAREBEEP:
s_snarebeep.start();
break;

case S_SNARENIKO:
s_snareniko.start();
break;

case S_SNARENOISE:
s_snarenoise.start();
break;

case S_TOMHIGH808:
s_tomhigh808.start();
break;

case S_TOMMID808:
s_tommid808.start();
break;

case S_TOMLOW808:
s_tomlow808.start();
break;

}
}

void samplePitch(int sound) {
switch(sound) {
case S_HAT808:
s_hat808.setFreq(pitch * (float) hat808_SAMPLERATE / (float) hat808_NUM_CELLS);
break;

case S_HATBEEP:
s_hatbeep.setFreq(pitch * (float) hatbeep_SAMPLERATE / (float) hatbeep_NUM_CELLS);
break;

case S_KICK808:
s_kick808.setFreq(pitch * (float) kick808_SAMPLERATE / (float) kick808_NUM_CELLS);
break;

case S_KICKBEEP:
s_kickbeep.setFreq(pitch * (float) kickbeep_SAMPLERATE / (float) kickbeep_NUM_CELLS);
break;

case S_KICKNOISE:
s_kicknoise.setFreq(pitch * (float) kicknoise_SAMPLERATE / (float) kicknoise_NUM_CELLS);
break;

case S_CLAVES808:
s_claves808.setFreq(pitch * (float) claves808_SAMPLERATE / (float) claves808_NUM_CELLS);
break;

case S_RIM808:
s_rim808.setFreq(pitch * (float) rim808_SAMPLERATE / (float) rim808_NUM_CELLS);
break;

case S_SHAKER:
s_shaker.setFreq(pitch * (float) shaker_SAMPLERATE / (float) shaker_NUM_CELLS);
break;

case S_CLAP808:
s_clap808.setFreq(pitch * (float) clap808_SAMPLERATE / (float) clap808_NUM_CELLS);
break;

case S_SNAREBEEP:
s_snarebeep.setFreq(pitch * (float) snarebeep_SAMPLERATE / (float) snarebeep_NUM_CELLS);
break;

case S_SNARENIKO:
s_snareniko.setFreq(pitch * (float) snareniko_SAMPLERATE / (float) snareniko_NUM_CELLS);
break;

case S_SNARENOISE:
s_snarenoise.setFreq(pitch * (float) snarenoise_SAMPLERATE / (float) snarenoise_NUM_CELLS);
break;

case S_TOMHIGH808:
s_tomhigh808.setFreq(pitch * (float) tomhigh808_SAMPLERATE / (float) tomhigh808_NUM_CELLS);
break;

case S_TOMMID808:
s_tommid808.setFreq(pitch * (float) tommid808_SAMPLERATE / (float) tommid808_NUM_CELLS);
break;

case S_TOMLOW808:
s_tomlow808.setFreq(pitch * (float) tomlow808_SAMPLERATE / (float) tomlow808_NUM_CELLS);
break;

}
}
