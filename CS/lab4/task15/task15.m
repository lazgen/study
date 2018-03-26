clear;
fun = menu('Select function', 'fix', 'floor', 'ceil');
while fun > 3 || fun < 1
    disp('Wrong selection');
    fun = menu('Select function', 'fix', 'floor', 'ceil');
end
num = rand*10;
fprintf('Num = %.3f\n',num);
switch fun
    case 1
    num_fix = fix(num);
    fprintf('fix: %.3f\n',num_fix);
    case 2
    num_floor = floor(num);
    fprintf('floor: %.3f\n',num_floor);
    case 3
    num_ceil = ceil(num);
    fprintf('ceil: %.3f\n',num_ceil);
end