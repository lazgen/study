clear; 
disp('This program will calculate the volume of a pyramid.');

length = input('Enter the length of the base: ');
lengthUnits = input('Is that i or c? ', 's');
if lengthUnits ~= 'i'
    length = length / 2.54;
end

width = input('Enter the width of the base: ');
widthUnits = input('Is that i or c? ', 's');
if widthUnits ~= 'i'
    width = width / 2.54;
end

height = input('Enter the height: ');
heightUnits = input('Is that i or c? ', 's');
if heightUnits ~= 'i'
    height = height / 2.54;
end

V = 1 / 3 * length * width * height;

fprintf('The volume of the pyramid is %3.3f cubic inches.\n',V);
