clear;
letter = input('Enter a letter ', 's');
counter = 0;
while (letter >= 'a' && letter <= 'z')  || (letter >= 'A' && letter <= 'Z')
    fprintf('Thanks, you entered letter %s \n', letter);
    counter = counter + 1;
    letter = input('Enter a letter ', 's');
end
 
fprintf('%s is not a letter \n', letter);
fprintf('You entered %d letters \n',counter);