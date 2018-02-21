clear;
M = load('floatnums.dat');
M1 = round(M);
save('intnums.dat', 'M1', '-ascii');