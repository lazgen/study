fprintf('Menu\n1. Cylinder\n2. Circle\n3. Rectangle\n')
answer = input('Selection: ');

if answer == 1
    r = input('Enter the cylinder radius: ');
    h = input('Enter the cylinder height: ');
    fprintf('S = %.f\n',pi * r * r * h)
elseif answer == 2
    r = input('Enter the circle radius: ');
    fprintf('S = %.f\n',pi * r * r)
elseif answer == 3
    w = input('Enter the rectangle width: ');
    h = input('Enter the rectangle height: ');
    fprintf('S = %.f\n', w * h)
else
    fprintf('Error\n');
end
        