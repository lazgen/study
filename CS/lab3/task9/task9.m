clear
letter = input('y or n? ', 's');
if letter == 'y' || letter == 'Y'
    disp('OK, continuing')
elseif letter == 'n' || letter == 'N'
    disp('OK, halting')
else
    disp('Error')
end