count = 1;
for c = 1:5
    for k=1:count
        fprintf('%-5d', c*k);
    end
    fprintf('\n');
    count = count + 1;
end