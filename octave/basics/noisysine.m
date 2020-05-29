## Author: Dov Kruger <dkruger@megatool>
## Created: 2020-05-20

function [retval] = noisysine (numberWaves, samples, noiseAmplitude)
  endpt=numberWaves*2*pi;
  t=0:endpt/(samples-1):endpt;
  r=(2*rand(1,samples) - 1)*noiseAmplitude;
  y = sin(t) + r;
  plot(t, y, 'ko', 'MarkerSize', 14);
endfunction
