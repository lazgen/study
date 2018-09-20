clear;

%% Import data
Tdata = importDataTable('data.xls');

%% Compose combinations
tic;

[rows,~] = size(Tdata);

C = accomnk(rows,2);

% combCount = length(C);

combCount = 4;

syms a2 a3 n2 n3;
        
firsteqn = (n2*a2^3)/(n2-1)^2 + (n3*(n3-a3)*(a3-1)^2)/(n3-1)^2 + (n2*n3*(a2-a3)^2*(n2*a3-n3*a2))/(n2-n3)^2 == 0;

secondeqn = a2^2/(1-n2) - ((a2-a3)*(n2*a3-n3*a2))/(n2-n3) - ((n3-a3)*(a3-1))/(n3-1) == 0;

S = solve([firsteqn, secondeqn], [a2, a3]);

for i = 1:combCount
    comb = C(i,:);
    rivec = [1; Tdata.nr(comb); 1];
    
    if rivec(2) ~= rivec(3)
%         eqns = subs([firsteqn, secondeqn], [n2,n3], rivec(2:3)');  
%         S = vpasolve(eqns, [a2, a3]);
        
        solvA2 = vpa(subs(S.a2, [n2, n3], rivec(2:3)'));
        solvA3 = vpa(subs(S.a3, [n2, n3], rivec(2:3)'));
%         disp(S);
        
    end
    
end

toc;



