function SNR_dB = TesteAudio(Pr)

% Ex: Pr = 0.001;

[g,fs] = audioread('DoceDeLeite.wav');

B = fs;

g = ( g(:,1) + g(:,2) )/2;

g = 0.5*g';


Pg = var(g);

r = sqrt(Pr)*randn(1,length(g));

y = g + r;

sound(0.5*[g y],fs);

SNR_dB = 10*log10(Pg/Pr);

SNR_dB
