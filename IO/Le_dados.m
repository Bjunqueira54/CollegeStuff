%--------------------------------------------------------------------------
%                   Fun��o que obt�m os dados do problema
%--------------------------------------------------------------------------
% Par�metros de entrada:
%--------------------------------------------------------------------------
% -
%--------------------------------------------------------------------------
% Par�metros de sa�da:
%--------------------------------------------------------------------------
% n = n� de variaveis
% m = n� de restri�oes
% c = vector dos coeficientes das variaveis na FO (1xn)
% A = matriz dos coeficientes tecnicos (mxn)
% b = vector dos termos independentes das restri�oes (mx1)
%--------------------------------------------------------------------------
function [n,m,c,A,b]=Le_dados()
    fprintf('\n-------------------- Dados do problema --------------------\n')
    n=input('Indique n� de variaveis: ');
    m=input('Indique n� de restri�oes: ');

    fprintf('\nCoeficientes das variaveis na Fun�ao Objectivo\n');
    flg=0;
    while(~flg)
        c=input('Introduza vector c[]:');
        if length(c)==n && isnumeric(c);
            flg=1;
        else
            disp('Dimensao do vector incorrecta!\n')
        end
    end
    
    fprintf('\nCoeficientes das variaveis nas restri�oes\n');
    while(flg)
        A=input('Introduza matriz A[;]:');
        [lin,col]=size(A);
        if lin~=m || col~=n
            disp('Dimensoes da matriz incorrectas!\n')
        else
            flg=0;
        end
    end

    fprintf('\nTermos independentes das restri�oes\n');
    while(~flg)
        b=input('Introduza vector b[]:');
        if length(b)==m
            flg=1;
        else
            disp('Dimensao do vector incorrecta!\n')
        end
    end
    b=b'; % Transp�e vector linha para coluna
end