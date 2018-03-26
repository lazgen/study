clear;
min = input('Please enter your minimum value: ');
max = input('Please enter your maximum value: ');
TheChoosenOne = input('Now enter your choice in this range ');

if TheChoosenOne < min || TheChoosenOne > max
    disp('Error')
else
    randNum = randi([min,max]);
    count = 1;
    while randNum ~= TheChoosenOne
        count = count + 1;
        randNum = randi([min,max]);
    end
    fprintf('It took %d tries to generate your number \n', count);
end