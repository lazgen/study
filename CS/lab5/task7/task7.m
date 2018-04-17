%% init
clear;
mat = randi([-10,10], 3, 5);
%% solution
a = max(mat, [], 1);
b = max(mat, [], 2);
c = max(max(mat, [], 1));
%% check
fprintf('mat:\n'); disp(mat);
fprintf('a:\n'); disp(a);
fprintf('b:\n'); disp(b);
fprintf('c:\n'); disp(c);
