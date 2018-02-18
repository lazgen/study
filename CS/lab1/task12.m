l = round(rand(1)*15);
vec = rand(2,l);
fprintf('vec:'); disp(vec);

fprintf('end:'); disp(vec(end));
fprintf('numel:'); disp(vec(numel(vec)));

[r, c] = size(vec);
fprintf('size:'); disp(vec(r, c));

flipped = rot90(vec,2);
fprintf('rot90:'); disp(flipped(1,1));