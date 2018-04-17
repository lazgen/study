function [result] = repvec(m, n)
result = reshape(repmat(m,n,1), 1, n * length(m));
end