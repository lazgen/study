clear;

mat = randi([0,100],3,10);
save 'dataFile.dat' mat -ascii;
load dataFile.dat;
disp(dataFile)

for s=1:size(dataFile,1)
    figure(s);
    plot(1:size(dataFile,2), dataFile(s,:));
    title(char('Row ', num2str(s)));
end