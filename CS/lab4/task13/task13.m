clear;
mat = randi([-10,10],1,5);
disp('Mat =');
disp(mat);

mat3 = zeros(1,5);
abs_mat = zeros(1,5);
counter = 0;
max = mat(1,1);
for s=1:5
    mat3(1,s) = mat(1,s) - 3;
    if mat(1,s) >= 0
        counter = counter + 1;
    end
    abs_mat(1,s) = abs(mat(1,s));
    if max < mat(1,s)
        max = mat(1,s);
    end
end

disp('Positive digits count:');
disp(counter);
disp('Max value:');
disp(max);

disp('Mat - 3 = ');
disp(mat3);
disp('abs(mat):');
disp(abs_mat);