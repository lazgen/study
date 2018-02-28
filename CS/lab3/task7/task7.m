x = randi([1 2^15], 1);
if(rem(x,2) == 0)
    disp('Even')
else
    disp('Odd')
end