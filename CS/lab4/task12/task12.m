function res = task12(mat)
sum = 0;
for s = 1:size(mat,1)
    for c = 1:size(mat,2)
        sum = sum + mat(s,c);
    end
end
res = sum /(s * c);
end

