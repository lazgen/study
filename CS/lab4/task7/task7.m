clear;
n = 10;
X = (1-1/n)^n;
Y = exp(1)^-1;
counter = 1;
while abs(Y-X) > 0.0001
    n = n + 1;
    counter = counter + 1;
    X = (1-1/n)^n;
end
fprintf('n = %d\n',n);