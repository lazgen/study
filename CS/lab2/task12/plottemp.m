clear;

data = load('temp.dat');
h = data(:,1);
t = data(:,2);
plot(h,t);
xlabel('height');
ylabel('temperature');
title('Temperature dependence on height')