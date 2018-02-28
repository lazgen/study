function outvec = flipvec(vec)

[r, c] = size(vec);

if r == 1 && c > 1
    outvec = fliplr(vec);
elseif c == 1 && r > 1
    outvec = flipud(vec);
else
    outvec = vec;
end