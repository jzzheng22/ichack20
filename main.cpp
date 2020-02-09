#include <iostream>
#include <cmath>
#include <fstream>

#include "AudioFile.h"
#include "FftRealPair.hpp"

std::string chooseNote(int maxIndex);

std::string audioAnalyse(std::string filename){
    AudioFile<double> audioFile;
    audioFile.load(filename);
    audioFile.printSummary();
    if(audioFile.isStereo()){
        audioFile.setNumChannels(1);
    }
    int length = audioFile.getNumSamplesPerChannel();
    std::cout << "Length " << length << std::endl;
    std::vector<double> imag(length, 0.0);
    std::vector<double> real;
    for(int i = 0; i < length; i++){
        real.push_back(audioFile.samples[0][i]);
        //std::cout << audioFile.samples[0][i] << std::endl;
    }
    Fft::transform(real, imag);
    std::vector<double> ampl;
    //std::vector<int> test_index;
    int maxIndex = 0;
    double max = 0.0;
    for(int i = 0; i < real.size(); i++){
        //std::cout << real[i] << " " << imag[i] << std::endl;
        double amplitude = std::sqrt(real[i] * real[i] + imag[i] * imag[i]);
        ampl.push_back(amplitude);
        if(i < real.size()/2 && amplitude > max){
            max = amplitude;
            maxIndex = i;
        }
        int x;
        //if(amplitude >= 5){
            //test_index.push_back(i);
            //std::cout << i << " " << amplitude << std::endl;
            //std::cin >> x;
        //}
        //std::cout << amplitude << std::endl;
    }
    //int premult = maxIndex * audioFile.getSampleRate() / audioFile.getNumSamplesPerChannel();
    int premult = maxIndex * audioFile.getLengthInSeconds();
    int test = premult * 100;
    double frequency = premult / 100.00;
    std::string note = chooseNote(test) + "," + std::to_string(frequency);
    std::cout << "note is " << note << std::endl;
    return note;
}

std::string chooseNote(int test){
    if((test % 1635) == 0){
        return "C";
    }
    else if((test % 1732) == 0 ){
        return "C#";
    }
    else if((test % 1835) == 0){
        return "D";
    }
    else if((test % 1945) == 0){
        return "D#";
    }
    else if((test % 2060) == 0){
        return "E";
    }
    else if((test % 2183) == 0){
        return "F";
    }
    else if((test % 2312) == 0){
        return "F#";
    }
    else if((test % 2450) == 0){
        return "G";
    }
    else if((test % 2596) == 0){
        return "G#";
    }
    else if((test % 2750) == 0){
        return "A";
    }
    else if((test % 2914) == 0){
        return "A#";
    }
    else if((test % 3087) == 0){
        return "B";
    }
    else{
        std::cout << test << std::endl;
        return "not a note";
    }
}
