clc
clear


a_1=1;
r=1;
n=4;

tic
a=gerarPa_v1(a_1,r,n);
toc
tic
b=gerarPa_v2(a_1,r,n);
toc
tic
c=gerarPa_v3(a_1,r,n);
toc
tic
d=gerarPa_v4(a_1,r,n);
toc

S=SomaPA(a);
fprintf('A soma da PA=%.2f\n',S);