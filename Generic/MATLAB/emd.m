function imf = emd(x)
% Empiricial Mode Decomposition (Hilbert-Huang Transform)
% imf = emd(x)
% Func : findpeaks

x   = transpose(x(:));
imf = [];
N = 1;
while ~ismonotonic(x)
   x1 = x;
   sd = Inf;
   while (sd > 0.1) | ~isimf(x1)
      s1 = getspline(x1);
      s2 = -getspline(-x1);
      x2 = x1-(s1+s2)/2;
      
      sd = sum((x1-x2).^2)/sum(x1.^2);
      x1 = x2;
   end
   
   if (N <= 8)
    imf = x1;
   end
   x          = x-x1;
   N = N + 1;
end

% FUNCTIONS

function u = ismonotonic(x)

u1 = length(findpeaks(x))*length(findpeaks(-x));
if u1 > 0, u = 0;
else,      u = 1; end

function u = isimf(x)

N  = length(x);
u1 = sum(x(1:N-1).*x(2:N) < 0);
u2 = length(findpeaks(x))+length(findpeaks(-x));
if abs(u1-u2) > 1, u = 0;
else,              u = 1; end

function s = getspline(x)

N = length(x);
p = findpeaks(x);
s = spline([0 p N+1],[0 x(p) 0],1:N);
