clear;

syms a2 a3 n2 n3;

firsteqn = (n2*a2^3)/(n2-1)^2 + (n3*(n3-a3)*(a3-1)^2)/(n3-1)^2 + (n2*n3*(a2-a3)^2*(n2*a3-n3*a2))/(n2-n3)^2 == 0;

secondeqn = a2^2/(1-n2) - ((a2-a3)*(n2*a3-n3*a2))/(n2-n3) - ((n3-a3)*(a3-1))/(n3-1) == 0;

S = solve([firsteqn, secondeqn], [a2, a3]);

nr1 = 1.6123;
nr2 = 1.5962;

subsA2 = subs(S.a2, [n2, n3], [nr1, nr2]);
subsA3 = subs(S.a3, [n2, n3], [nr1, nr2]);

solvA2 = vpa(subs(S.a2, [n2, n3], [nr1, nr2]));
solvA3 = vpa(subs(S.a3, [n2, n3], [nr1, nr2]));
