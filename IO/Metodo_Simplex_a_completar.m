%--------------------------------------------------------------------------
%                  Implementa�ao do Metodo Simplex
%--------------------------------------------------------------------------
% Variaveis principais:
%--------------------------------------------------------------------------
% n = n� de variaveis originais
% m = n� de restri�oes funcionais
% A = matriz dos coeficientes t�cnicos
% b = vector dos termos independentes das restri��es
% c = vector dos coeficientes das variaveis na FO
% x = vector com os indices de todas as variaveis
% xB = vector com os indices das variaveis b�sicas
% cB = vector com os coeficientes das variaveis b�sicas na FO 
% Zjcj = vector com os valores da linha Zj-cj
% Z = valor da FO
% SBA = vector com os valores da SBA em cada itera��o
%--------------------------------------------------------------------------

% Limpa janela de comandos
clc 
disp('-----------------------------------------------------------')
disp('        Resolu��o de um problema pelo m�todo Simplex       ')
disp('-----------------------------------------------------------')
disp(' Assume-se que:                                            ')
disp(' -> Fun��o objectivo est� na forma de maximiza��o          ')
disp(' -> Todas as restri��es s�o de "<="                        ')
disp(' -> Todas as vari�veis s�o >=0                             ')
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

SBA=[zeros(n,1);b];     % Inicializa�ao da 1� SBA (vector coluna)

Zjcj=zeros(1,n+m);      % Inicializa��o do vector Zjcj a zeros

termina=0;              % Controla a execu�ao do ciclo
iteracao=1;             % Contabiliza o n� de itera�oes
while ~termina
   
    % Completar c�digo 

end
