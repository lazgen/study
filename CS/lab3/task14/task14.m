clear; 
s = input('Enter one symbol ', 's');
upper = char(65:90);
lower = char(97:122);
if contains(upper, s) || contains(lower, s)
    disp('Is a char');
else
    disp('Is not a char');
end