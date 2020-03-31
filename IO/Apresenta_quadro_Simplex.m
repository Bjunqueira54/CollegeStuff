%--------------------------------------------------------------------------
%        Fun�ao que constroi e apresenta um quadro Simplex no ecr� 
%--------------------------------------------------------------------------
% Par�metros de entrada:
%--------------------------------------------------------------------------
% n = n� de variaveis
% m = n� de restri�oes
% c = vector dos coeficientes das variaveis na FO
% xB = vector com os indices das variaveis basicas
% cB = vector com os coeficientes das variaveis basicas na FO 
% A = matriz dos coeficientes tecnicos
% b = vector dos termos independentes das restri�oes
% Zjcj = vector que contem os valores da linha Zj-cj
% Z = valor da FO
% iteracao = n� da itera��o
% flag = indica se quadro � �ptimo (0) ou n�o (1)
% VN = vari�vel que vai entrar para a base
% VNB = vari�vel que vai sair da base 
%--------------------------------------------------------------------------
% Par�metros de sa�da:
%--------------------------------------------------------------------------
% -
%--------------------------------------------------------------------------
function Apresenta_quadro_Simplex(n,m,c,xB,cB,A,b,Zjcj,Z,iteracao,flag,VB,VNB)
    
    fprintf('%d� Itera�ao:\n',iteracao)
    
    fprintf('\n')
    for i=1:15
        fprintf(' ');
    end
    for j=1:n+m
        fprintf('%-10.1f',c(j))
    end
    fprintf('\n')
    for i=1:15
        fprintf(' ');
    end
    for j=1:n+m
        fprintf('x%-9.0f',j)
    end
    fprintf('b\n')
    for i=1:15
        fprintf('-');
    end
    for j=1:(n+m+1)*10
        fprintf('-')
    end
    fprintf('\n')
    for i=1:m
        fprintf('x%-3.0f%-11.1f',xB(i),cB(i))
        for j=1:n+m
            fprintf('%-10.1f',A(i,j))
        end
        fprintf('%-10.1f\n',b(i))
    end
    for i=1:15
        fprintf('-');
    end
    for j=1:(n+m+1)*10
        fprintf('-')
    end
    fprintf('\n')
    fprintf('Zj-cj')
    for i=1:10
        fprintf(' ');
    end
    for j=1:n+m
        fprintf('%-10.1f',Zjcj(j))
    end
    fprintf('%-10.1f\n\n',Z)
    
    if flag
        fprintf('Variavel que vai tornar-se VB -> x%d\n',VB)
        fprintf('Variavel que vai tornar-se VNB -> x%d\n\n\n',VNB) 
    end
end
