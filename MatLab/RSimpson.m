% Bruno Miguel Almeida Junqueira
% 21270345
% P7
% 21/03/2019

function S = RSimpson(f, a, b, n)

h = ((b - a) / n);

x = a;

s = 0;

for i = 1:h:n-1
    x = x + h;
    if(isEven(i))
        s = s + (2 * f(x));
    else
        s = s + (4 * f(x));
    end
end

s = h/3 * (f(a) + s + f(b));