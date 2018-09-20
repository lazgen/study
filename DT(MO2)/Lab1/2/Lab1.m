% Decision theory
% First lab 3 var
% Ibetullov Yuriy
% TPU 8VM71 

%% 3.2
clear
x = 0:1:2*10^3;
plot(x, f1(x),'r');
hold on;
plot(x, f2(x),'b');
hold on;
plot(x, f3(x),'k');
hold on;
plot(x, f4(x),'k');
hold on;
% legend('y = (x^2 + 4) / 2;','y = (5*x - 4) / 2;','y = 4 - x;')
xlabel('X')
ylabel('Y')