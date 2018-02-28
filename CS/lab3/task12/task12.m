clear;
disp('Find ellipse eccentricity');
a = input('Enter a = ');
b = input('Enter b = ');

if a == 0
    disp('Error');
else
    disp(eccentricity(a,b));
end