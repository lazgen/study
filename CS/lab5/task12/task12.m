%% init
clear;
%% solution
hightemp = load('hightemp.dat');
newmat = hightemp;
newmat(:, 1) = newmat(:, 1) + 1900;
save 'y2ktemp.dat' newmat -ascii
%% check
disp('a:'); disp(hightemp);
disp('b:'); disp(newmat);