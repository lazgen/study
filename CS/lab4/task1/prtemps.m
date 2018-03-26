clear;

fprintf('Enter the temp in Degrees C in range from -16 to 20.\n');
tempMax = input('Enter a maximum temperature: ');

while (tempMax < -16 || tempMax > 20)
    tempMax = input('Error! Enter a maximum temperature ');
end

maxFar = 9/5*tempMax+32;
a = 1;

fprintf('%-6.1s %-6.1s \n', 'F', 'C');
for k = 0:5:maxFar
    fprintf('%-6.1f %-6.1f \n', k, 5/9*(k-32));
end
