%% init
clear;
n = 1000;
%% solution
% a) false init
s = tic;
for c = 1:n
    mat = false(n);
end
banchmarkA = toc(s) / n;
%
% b) logical init
s = tic;
for c = 1:n
    mat = logical(zeros(n));
end
banchmarkB = toc(s) / n;
%% display
fprintf('Logical matrix (%3.fx%3.f) init banchmarks:\n',n,n);
fprintf('a) With false func:   %f s\n', banchmarkA);
fprintf('b) With logical func: %f s\n', banchmarkB);