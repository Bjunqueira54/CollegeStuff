%--------------------------------------------------------------------------
%                  Implementaçao do Metodo Simplex
%--------------------------------------------------------------------------
% Variaveis principais:
%--------------------------------------------------------------------------
% n = nº de variaveis originais
% m = nº de restriçoes funcionais
% A = matriz dos coeficientes técnicos
% b = vector dos termos independentes das restrições
% c = vector dos coeficientes das variaveis na FO
% x = vector com os indices de todas as variaveis
% xB = vector com os indices das variaveis básicas
% cB = vector com os coeficientes das variaveis básicas na FO 
% Zjcj = vector com os valores da linha Zj-cj
% Z = valor da FO
% SBA = vector com os valores da SBA em cada iteração
%--------------------------------------------------------------------------

% Limpa janela de comandos
clc 
disp('-----------------------------------------------------------')
disp('        Resolução de um problema pelo método Simplex       ')
disp('-----------------------------------------------------------')
disp(' Assume-se que:                                            ')
disp(' -> Função objectivo está na forma de maximização          ')
disp(' -> Todas as restrições são de "<="                        ')
disp(' -> Todas as variáveis são >=0                             ')
disp('-----------------------------------------------------------')
% Le dados do problema
[n,m,c,A,b]=Le_dados;

% Limpa novamente janela de comandos
clc

I=eye(m);       % Matriz identidade (mxm)
A=[A I];        % Matriz A do problema na forma aumentada
cs=zeros(1,m);  % Coeficientes das variaveis slack na FO
c=[c cs];       % Coeficientes de todas as variaveis na FO

xo=1:n;         % Indices das variaveis originais
xs=n+1:n+m;     % Indices das variaveis slack
x=[xo xs];      % Indices de todas as variaveis

xB=xs';         % xB e um vector coluna com os indices das VBs
cB=cs';         % cB e um vector coluna com os coeficientes das VBs na FO

SBA=[zeros(n,1);b];     % Inicializaçao da 1ª SBA (vector coluna)

Zjcj=zeros(1,n+m);      % Inicialização do vector Zjcj a zeros

termina=0;              % Controla a execuçao do ciclo
iteracao=1;             % Contabiliza o nº de iteraçoes
while ~termina
   
    % Completar código 

end
