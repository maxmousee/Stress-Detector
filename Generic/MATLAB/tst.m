%Fs = 800; L = 1000;
%t = (0:L-1)'/Fs;
%x = sin(2*pi*250*t) + 0.75*cos(2*pi*340*t);
%y = x + .5*randn(size(x)); % noisy signal
%hfft = dsp.FFT('FFTLengthSource', 'Property', ...
%    'FFTLength', 1024);
%Y = hfft(y);
%plot(Fs/2*linspace(0,1,512), 2*abs(Y(1:512)/1024));
%title('Single-sided amplitude spectrum of noisy signal y(t)');
%xlabel('Frequency (Hz)'); ylabel('|Y(f)|');

 %hfft = dsp.FFT('FFTLengthSource', 'Property', ... 
   % 'FFTLength', 512);
 %Y = hfft(stressComponentArray); 
 
 %plot(f,P1)
 %title('Single-Sided Amplitude Spectrum of X(t)')
 %xlabel('f (Hz)')
 %ylabel('|P1(f)|')
 
 [x, Fs] = audioread('rain_man_driver_8000.wav');
 expanded = zeros(size(8000));
 
 for idx = 1:numel(x)
    expanded(idx) = x(idx);
 end

 transp = expanded';
 
vsd(transp);