clear;

%  remove old changes
save 'pos.dat' -ascii;
save 'neg.dat' -ascii;

N = input('Input digits count: ');
count = 1;
for c = 1:N
    a = input(char(num2str(c),': '));
    if a >= 0
        save 'pos.dat' a -append -ascii
    else
        save 'neg.dat' a -append -ascii
    end
end

load('pos.dat')
disp('pos.dat'); disp(pos);
load('neg.dat')
disp('neg.dat'); disp(neg)