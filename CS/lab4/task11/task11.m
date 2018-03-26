clear;
mat = randi([-50, 50],3,5);
disp(mat)
max_row(1,:) = mat(:,1);
max_col(1,:) = mat(1,:);
max_mat = mat(1,1);
for c = 1:3
    for s = 1:5
        if max_row(1,c) < mat(c,s)
            max_row(1,c) = mat(c,s);
        end
        if max_col(1,s) < mat(c,s)
            max_col(1,s) = mat(c,s);
        end
        if max_mat < mat(c,s)
            max_mat = mat(c,s);
        end
    end
end
fprintf('Max from rows: \n');
fprintf('%d ', max_row);
fprintf('\n');
fprintf('Max from columns: \n');
fprintf('%d ', max_col);
fprintf('\n');
fprintf('Max from matrinx: \n');
fprintf('%d ', max_mat);
fprintf('\n');
        