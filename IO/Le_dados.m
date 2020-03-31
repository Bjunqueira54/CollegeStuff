%--------------------------------------------------------------------------
%                   Função que obtém os dados do problema
%--------------------------------------------------------------------------
% Parâmetros de entrada:
%--------------------------------------------------------------------------
% -
%--------------------------------------------------------------------------
% Parâmetros de saída:
%--------------------------------------------------------------------------
% n = nº de variaveis
% m = nº de restriçoes
% c = vector dos coeficientes das variaveis na FO (1xn)
% A = matriz dos coeficientes tecnicos (mxn)
% b = vector dos termos independentes das restriçoes (mx1)
%--------------------------------------------------------------------------
function [n,m,c,A,b]=Le_dados()
    fprintf('\n-------------------- Dados do problema --------------------\n')
    n=input('Indique nº de variaveis: ');
    m=input('Indique nº de restriçoes: ');

    fprintf('\nCoeficientes das variaveis na Funçao Objectivo\n');
    flg=0;
    while(~flg)
        c=input('Introduza vector c[]:');
        if length(c)==n && isnumeric(c);
            flg=1;
        else
            disp('Dimensao do vector incorrecta!\n')
        end
    end
    
    fprintf('\nCoeficientes das variaveis nas restriçoes\n');
    while(flg)
        A=input('Introduza matriz A[;]:');
        [lin,col]=size(A);
        if lin~=m || col~=n
            disp('Dimensoes da matriz incorrectas!\n')
        else
            flg=0;
        end
    end

    fprintf('\nTermos independentes das restriçoes\n');
    while(~flg)
        b=input('Introduza vector b[]:');
        if length(b)==m
            flg=1;
        else
            disp('Dimensao do vector incorrecta!\n')
        end
    end
    b=b'; % Transpõe vector linha para coluna
end