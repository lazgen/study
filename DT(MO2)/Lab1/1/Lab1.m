% Decision theory
% First lab 3 var
% Ibetullov Yuriy
% TPU 8VM71

%% 
% g1(x1,x2) = x1^2 - 2*x2 + 4 >= 0;
% g2(x1,x2) = 5*x1 - 2*x2 - 4 <= 0;
% g1(x1,x2) = x1 + x2 - 4 = 0;

% x1 = x; x2 = y;

% y = (x^2 + 4) / 2;
% y = (5*x - 4) / 2;
% y = 4 - x;

%%
clear
x = -5:0.1:5;

plot(x, f1(x),'r');
hold on;
plot(x, f2(x),'b');
hold on;
plot(x, f3(x),'k');
hold on;
legend('y = (x^2 + 4) / 2;','y = (5*x - 4) / 2;','y = 4 - x;')
xlabel('X')
ylabel('Y')