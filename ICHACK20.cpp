#include <iostream>

#include <complex>

#include "AudioFile.h"

#include "FftComplex.hpp"

int main(int argc, char *argv[]){
    AudioFile<std::complex<double>> audioFile;
    audioFile.load(argv[1]);
    if(audioFile.isStereo()){
        audioFile.setNumChannels(1);
    }
    transform(audioFile.samples[0]);


    return 0;
}