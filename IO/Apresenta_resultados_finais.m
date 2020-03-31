%--------------------------------------------------------------------------
%       Funçao que apresenta a soluçao optima e o valor de Z optimo
%--------------------------------------------------------------------------
% Parâmetros de entrada:
%--------------------------------------------------------------------------
% n = nº de variaveis
% m = nº de restriçoes
% Z = valor da FO
% SBA = vector que contem os valores da SBA actual
%--------------------------------------------------------------------------
% Parâmetros de saída:
%--------------------------------------------------------------------------
% - 
%--------------------------------------------------------------------------
function Apresenta_resultados_finais(n,m,SBA,Z)
    fprintf('\n=> Quadro optimo pois nao existem valores negativos na linha Zj-cj\n')
    fprintf('\nSoluçao optima:\n')
    fprintf('-------------------------------\n')
    for j=1:n+m
        fprintf('\tx%d* = %.2f\n',j,SBA(j))
    end
    fprintf('\nValor optimo de Z:\n');
    fprintf('-------------------------------\n')
    fprintf('\tZ*=%.2f\n',Z)
end
