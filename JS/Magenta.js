var fs = require('fs');
const WaveFile = require('wavefile').WaveFile;
let wav = new WaveFile(fs.readFileSync("32_bit_float.wav"));
wav.toBitDepth("32");
fs.writeFileSync("32bit-file.wav", wav.toBuffer());


const model = require('@magenta/music/node/music_vae');
const core = require('@magenta/music/node/core');

const globalAny: any = global;
globalAny.performance = Date;
globalAny.fetch = require('node-fetch');

const model = new mode.MusicVAE('magentadata/js/checkpoints/music_vae/drums_2bar_lokl_small');
const player = new core.Player();
model
  .initialize()
  .then(() => model.sample(1))
  .then(samples => {
    player.resumeContext();
    player.start(samples[0])
  });