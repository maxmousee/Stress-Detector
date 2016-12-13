function stressFreq = vsd(input)
 Fs = length(input);
 imf = emd(input(1:Fs));
 stressComponentArray = imf;
 L = length(stressComponentArray);
 %Y=fft(stressComponentArray, L);
 %fft starts here
 hfft = dsp.FFT('FFTLengthSource', 'Property', ...
    'FFTLength', 8000);
 Y = hfft(stressComponentArray); 
 
 %fft ends here
 P2 = abs(Y/L);
 P1 = P2(1:L/2+1);
 P1(2:end-1) = 2*P1(2:end-1);
 f = Fs*(0:(L/2))/L;
 [val,index] = max(P1);
 stressFreq = index - 1;