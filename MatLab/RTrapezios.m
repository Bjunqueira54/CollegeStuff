% Bruno Miguel Almeida Junqueira
% 21270345
% P7
% 21/03/2019

%Declaração do algoritmo para o método dos Trapézios
function T = RTrapezios(f, a, b, n)

h = ((b - a) / n);

x = a;

s = 0;

for i = 1 : h : (n-1)
    x = x + h;
    s = s + f(x);
end

T = h/2 * (f(a) + 2*s + f(b));