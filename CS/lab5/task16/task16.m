%% init
clear;
letter = 'x';
n = 1000;
%% solution
% a) switch
s = tic;
for c = 1:n
switch letter
    case 'x'
        disp('Hello')
    case {'y', 'Y'}
        disp('Yes')
    case 'Q'
        disp('Quit')
    otherwise
        disp('Error')
end % switch end
end % for end
banchmarkA = toc(s) / n;
%
% b) if-else
s = tic;
for c = 1:n
if (letter == 'x')
    disp('Hello');
elseif(letter == 'y' || letter == 'Y')
    disp('Yes');
elseif(letter == 'Q')
    disp('Quit');
else
    disp('Error');
end % if end
end % for end
banchmarkB = toc(s) / n;
%% display
fprintf('Branch construct banchmarks:\n');
fprintf('a) switch:  %f s\n', banchmarkA);
fprintf('b) if-else: %f s\n', banchmarkB);