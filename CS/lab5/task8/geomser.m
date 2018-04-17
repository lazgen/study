function [result] = geomser(r, n)
n = 0:n;
result = sum(r.^n);
end