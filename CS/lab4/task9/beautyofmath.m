clear;
count = 9;
d = 0;
for s = 1:9
    d = 10*d+s;
    result = d*8+s;
    fprintf('%d * 8 + %d = %d\n', d, s, result);
end