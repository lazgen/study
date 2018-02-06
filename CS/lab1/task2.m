vec = input('Enter the vector:');
middle = fix(length(vec)/2);
left = vec(1:1:middle);
right = vec(middle+1:1:end);
disp(left);
disp(right);