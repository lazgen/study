%% init
clear;
n = randi(10);
vec = 1:2:n;
%% solution
quadV = vec.^2;
%% display
plot(vec, quadV);
%% check
disp('n:'); disp(n);
disp('vec:'); disp(vec);
disp('quad:'); disp(quadV);