function stressFreq = vsd(input)
 %Fs = length(input);
 %The code has fixed length anyway, so it wont work with different
 %sample rate anyway
 Fs = 8192;
 imf = emd(input(1:Fs));
 stressComponentArray = imf;
 L = length(stressComponentArray);
 %fft starts here
 Y = complex(zeros(size(stressComponentArray),class(stressComponentArray)));
 %dirty hack because matlab only generates fft code for power of 2
 %nPointDFT=nextpow2(L);
 %remember that nPointDFT should be a power of 2 or matlab coder wont
 %generate anything
 Y=fft(stressComponentArray, 8192);
 %fft ends here
 P2 = abs(Y/L);
 P1 = P2(1:L/2+1);
 P1(2:end-1) = 2*P1(2:end-1);
 f = Fs*(0:(L/2))/L;
 [val,index] = max(P1);
 stressFreq = index - 1;