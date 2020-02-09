var fft = require('fft-js').fft,
    fftUtil = require('fft-js').util,
    signal = [1,0,1,0];

var phasors= fft(signal);

var frequencies = fftUtil.fftFreq(phasors, 8000), // Sample rate and coef is just used for length, and frequency step
    magnitudes = fftUtil.fftMag(phasors); 

var both = frequencies.map(function (f, ix) {
    return {frequency: f, magnitude: magnitudes[ix]};
});
