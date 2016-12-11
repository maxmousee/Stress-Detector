function stressFreq = vsd(input)
 Fs = length(input);
 imf = emd(input(1:Fs));
 N = length(imf) - 1;
 if (N < 3)
     stressFreq = -1;
     return;
 end
 if (N > 5)
     N = N - 4;
 end
 stressComponentCell = imf(N);
 stressComponentArray = [stressComponentCell{1,:}];
 L = length(stressComponentArray);
 Y=fft(stressComponentArray);
 P2 = abs(Y/L);
 P1 = P2(1:L/2+1);
 P1(2:end-1) = 2*P1(2:end-1);
 f = Fs*(0:(L/2))/L;
 [val,index] = max(P1);
 stressFreq = index - 1;
 %disp('val');
 %disp(val);
 %disp('stressFreq');
 %disp(stressFreq);
 %plot(f,P1)
 %title('Single-Sided Amplitude Spectrum of X(t)')
 %xlabel('f (Hz)')
 %ylabel('|P1(f)|')
