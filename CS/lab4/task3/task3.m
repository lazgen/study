clear; 
num = input('Input the positive number: ');
counter = 1;
vec = [];
while num > 0
    vec(end+1) = num;
    counter = counter + 1;
    num = input('Input the positive number: ');
end
fprintf('You are input an negative number\n');
fprintf('%.0f ',vec);
fprintf('\n');