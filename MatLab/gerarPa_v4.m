function a=gerarPa_v4(a_1,r,n)
a=a_1:r:a_1+(n-1); 
i=2;
while (1)
    a(i)=a(1)+(i-1)*r;
    i=i+1;
    if i>n
        break;
    end
end