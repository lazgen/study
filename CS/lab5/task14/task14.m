%% init
clear;
vec = 0:0.5:10;
%% solution
var = input('Enter an variable: ');
while(~(any(vec == var)))
    var = input('Enter an variable: ');
end
%% display
disp('var'); disp(var)
