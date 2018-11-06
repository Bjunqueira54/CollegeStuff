#include <stdio.h>

int arredondaMedia(float n1, float n2)
{
    float media, dif;
    int mediaint;

    media=(n1+n2)/2;

    mediaint=(int)media;
    dif=media-mediaint;
    if(dif<0.5)
    {
        return mediaint;
    }
    return mediaint+1;
}

void main()
{
    float n1, n2;

    printf("Introduza o primeiro numero: ");
    scanf("%f", &n1);

    printf("Introduza o segundo numero: ");
    scanf("%f", &n2);

    printf("O valor arredondado da media entre %5.2f e %5.2f e %i", n1, n2, arredondaMedia(n1, n2));
}
