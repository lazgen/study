x = input('Enter the X: ');
answer = menu('Choose a function', 'sin(x)', 'cos(x)', 'tan(x)');
if answer == 1
    fprintf('sin(x) is %.f\n',sin(x))
elseif answer == 2
    fprintf('cos(x) is %.f\n',cos(x))
elseif answer == 3
    fprintf('tan(x) is %.f\n',tan(x))
else
    fprintf('Error\n');
end;
        