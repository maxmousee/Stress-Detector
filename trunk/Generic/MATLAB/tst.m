Fs = 800; L = 1000;
t = (0:L-1)'/Fs;
x = sin(2*pi*250*t) + 0.75*cos(2*pi*340*t);
y = x + .5*randn(size(x)); % noisy signal
hfft = dsp.FFT('FFTLengthSource', 'Property', ...
    'FFTLength', 1024);
Y = hfft(y);