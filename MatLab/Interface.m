clc
clear

disp('------------------')
disp('--------PA--------')
a_1=1;
r=1;
n=str2num(input('n=','s'));
disp(n)

disp('------------------')
disp('----GerarPA_v1----')

a=gerarPa_v1(a_1,r,n);
disp(a)

disp('------------------')
disp('----GerarPA_v2----')

b=gerarPa_v2(a_1,r,n);
disp(b)

disp('------------------')
disp('----GerarPA_v3----')

c=gerarPa_v3(a_1,r,n);
disp(c)

disp('------------------')
disp('----GerarPA_v4----')

d=gerarPa_v4(a_1,r,n);
disp(d)


S=SomaPA(a);
fprintf('A soma da PA=%.2f\n',S);