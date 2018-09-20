function A = accomnk(n,k)
% Calculation of the number of all accommodations by the formula
% n!/(n-k)!
v = 1:n;
A = [nchoosek(v, k); nchoosek(fliplr(v), k)];
end

