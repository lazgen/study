function plotsin(n)
%show sin from 0 to Pi with n points
x = linspace(0, pi, n);
figure();
plot(x,sin(x),'.-');
xlabel('x');
ylabel('sin(x)');
title(['sin(x), ', num2str(n), ' points']);
end
