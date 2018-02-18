l = round(rand(1)*15);
vec = rand(1,l);
fprintf('vec:'); disp(vec);

fprintf('length:'); disp(vec(length(vec)));
fprintf('end:'); disp(vec(end));
fprintf('numel:'); disp(vec(numel(vec)));

[r, c] = size(vec);
fprintf('size:'); disp(vec(c));

flipped = fliplr(vec);
fprintf('fliplr:'); disp(flipped(1));