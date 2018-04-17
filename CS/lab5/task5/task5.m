%% init
clear;
vec = randi([1,10], 1, 6);
%% solution
lastVal = cumsum(vec);
%% check
lastVal(end) == sum(vec)