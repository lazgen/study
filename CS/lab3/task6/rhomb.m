clear
d1 = input('Enter rhombus first diagonal: ');
d2 = input('Enter rhombus second diagonal: ');
if(d1 <= 0 || d2 <= 0)
    disp('Error')
else
   fprintf('S = %.2f\n',rhombarea(d1,d2)); 
end