function picked = pickone(x)
index = randi([1, length(x)]);
picked = x(index);
end