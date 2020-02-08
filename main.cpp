#include <iostream>

#include "AudioFile.h"

int main(int argc, char *argv[]){
    AudioFile<double> audioFile;
    audioFile.load(argv[1]);
    if(audioFile.isStereo()){
        audioFile.setNumChannels(1);
    }
    for(int i = 0; i < audioFile.getNumSamplesPerChannel(); i++){
        double currentSample = audioFile.samples[0][i];
    }

    return 0;
}
