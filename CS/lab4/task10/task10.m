mat = randi(3,4);
[row, col] = size(mat);
for c = 1:row
    fprintf('The product of row %d is %d\n', c, prod(mat(c,:)));
end