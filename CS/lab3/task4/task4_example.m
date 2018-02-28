num = input('Num = ');

if num < -2 || num > 4
    f1(num)
else
    if num <= 2
        if num >= 0
            f2(num)
        else
            f3(num)
        end
    else
        f4(num)
    end
end
