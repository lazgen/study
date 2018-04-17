%% init
clear;
vec = randi([3,5], 1, 5);
%% solution
newv = cumprod(vec);
%% display
disp('vec'); disp(vec); 
disp('newv'); disp(newv); 