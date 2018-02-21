clear;

%load data from file
M = load('costsales.dat');
[r, c] = size(M);
fprintf('There are %d rows in the matrix\n', r);

%plot
plot(1:r,M);
hold on;
legend('M(:,1)', 'M(:,2)');
xlabel('x');
ylabel('M');

%rotate matrix and save to newfile
M1 = rot90(M);
save newfile.dat M1 -ascii;

