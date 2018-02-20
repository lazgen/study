clear;

M1 = randi([50, 100],3,6);
disp('M1 = '); disp(M1);
save randfile.dat M1 -ascii;
M2 = randi([50, 100],2,6);
disp('M2 = '); disp(M2);

save randfile.dat M2 -ascii -append;
load 'randfile.dat';
M1(4:5, :) = M2;
disp('M == randfile'); disp(M1 == randfile);