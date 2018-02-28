function out = createvecMToN(m,n)

step = sign(n-m);
if(m == n)
    out = m;
else
    out = m:step:n;
end

end