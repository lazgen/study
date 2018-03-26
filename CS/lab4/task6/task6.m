clear;
h = input('Cone h = ');
r = input('Cone r = ');
while h < 0 || r < 0
    disp('Try more');
    h = input('Cone h = ');
    r = input('Cone r = ');
end
V = pi*r*r*h/3;
fprintf('V = %.3f\n',V);