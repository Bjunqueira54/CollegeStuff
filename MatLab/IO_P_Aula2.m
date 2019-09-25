clc
clear;
m = input('Nº de linhas: ');
fprintf('\n');
n = input('Nº de colunas: ');

x = input('Limite de valores (-x, x): ');

A = rand(m,n);
A = round(x - 2 * x * A);

c_neg = 0;
c_pos = 0;
c_zero = 0;

for i = 1:m
    for j = 1:n
        if A(i,j) < 0
            c_neg = c_neg + 1;
        elseif A(i, j) > 0
            c_pos = c_pos + 1;
        else
            c_zero = c_zero + 1;
        end
    end
end

A

fprintf('% de negativos: ');
(c_neg/(m*n)) * 100
fprintf('% de positivos: ');
(c_pos/(m*n)) * 100
fprintf('% de zeros: ');
(c_zero/(m*n)) * 100