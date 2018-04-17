%% init
clear;
vec = randi([1,20], 1, 6);
%% solution
maximum = max(vec);
minimum = min(vec);
sumVec = cumsum(vec);
%% display
disp('max'); disp(maximum); 
disp('min'); disp(minimum);
disp('sum'); disp(sumVec);