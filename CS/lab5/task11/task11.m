%% init
clear;
values = randi([-10 10], randi([1,5],1,1), randi([1,7],1,1));
save 'oldfile.dat' values -ascii
%% solution
mat = load('oldfile.dat');
c = min(size(mat, 1), size(mat,2));
squareMat = mat(1:c, 1:c);
save 'squarefile.dat' squareMat -ascii
%% check
disp('mat:'); disp(mat);
disp('squareMat:'); disp(squareMat);