%--------------------------------------------------------------------------
%       Fun�ao que apresenta a solu�ao optima e o valor de Z optimo
%--------------------------------------------------------------------------
% Par�metros de entrada:
%--------------------------------------------------------------------------
% n = n� de variaveis
% m = n� de restri�oes
% Z = valor da FO
% SBA = vector que contem os valores da SBA actual
%--------------------------------------------------------------------------
% Par�metros de sa�da:
%--------------------------------------------------------------------------
% - 
%--------------------------------------------------------------------------
function Apresenta_resultados_finais(n,m,SBA,Z)
    fprintf('\n=> Quadro optimo pois nao existem valores negativos na linha Zj-cj\n')
    fprintf('\nSolu�ao optima:\n')
    fprintf('-------------------------------\n')
    for j=1:n+m
        fprintf('\tx%d* = %.2f\n',j,SBA(j))
    end
    fprintf('\nValor optimo de Z:\n');
    fprintf('-------------------------------\n')
    fprintf('\tZ*=%.2f\n',Z)
end
