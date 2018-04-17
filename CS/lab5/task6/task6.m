%% init
clear;
vec = randi([-10,10], 1, 5);
%% solution
a = vec - 3;
b = length(vec(vec > 0));
c = abs(vec);
d = max(vec);
%% check
fprintf('vec:\n'); disp(vec);
fprintf('a:\n'); disp(a);
fprintf('b:\n'); disp(b);
fprintf('c:\n'); disp(c);
fprintf('d:\n'); disp(d);