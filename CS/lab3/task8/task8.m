clear
C = input('Enter the temp in degree C: ');
answer = input('Do you want K or F? ', 's');

if answer == 'K'
    K = C + 273.15;
    fprintf('The temp in degrees K is %.1f\n',K);
else
    F = 9 / 5 * C + 32;
    fprintf('The temp in degrees F is %.1f\n',F);
end