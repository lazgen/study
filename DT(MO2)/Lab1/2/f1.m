function y = f1(x)
a = x * 0.6 * 10^-6;
b = (x * 10^-9) - (0.6 * 10^-6);
y = a ./ b;
end