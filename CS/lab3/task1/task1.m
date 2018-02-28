function output = task1(digit) 
answer = menu('Choose a function', 'Ceil', 'Round', 'Sign');
switch answer
    case 1
        output = ceil(digit);
    case 2
        output = round(digit);
    case 3
        output = sign(digit);
    otherwise
        output = -1;
end

