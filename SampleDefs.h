Sample <closedhat_NUM_CELLS, AUDIO_RATE> s_hat_808(closedhat_DATA);
Sample <snare_NUM_CELLS, AUDIO_RATE> s_snare_niko(snare_DATA);
Sample <kick_NUM_CELLS, AUDIO_RATE> s_kick_808(kick_DATA);
Sample <clap_NUM_CELLS, AUDIO_RATE> s_clap(clap_DATA);

int sampleNext(int sound) {
  int nextOut;
  switch(sound) {
    case HAT_808:
    nextOut = s_hat_808.next();
    break;

    case SNARE_NIKO:
    nextOut = s_snare_niko.next();
    break;

    case KICK_808:
    nextOut = s_kick_808.next();
    break;

    case CLAP:
    nextOut = s_clap.next();
    break;

    default:
    nextOut = 0;
  }
  return nextOut;
}

void sampleStart(int sound) {
  switch(sound) {
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

void samplePitch(int sound) {
  switch(sound) {
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

