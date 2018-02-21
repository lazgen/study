clear;
b = input('Enter the first side: ');
c = input('Enter the second side: ');
angle = input('Enter the angle between them: ');
a = sqrt(b^2 + c^2 - 2*b*c*cos(angle));
fprintf('The third side is %.3f\n', a);