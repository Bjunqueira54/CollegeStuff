#include <stdio.h>
#include <stdlib.h>

int main(int argc, char** argv)
{
    FILE *f = fopen("../Test Binary Files/teste.bin", "rb");
    int elementos, nchar, nif;
    char nome[50];
    
    if(!f)
    {
        fprintf(stderr, "Erro ao abrir o ficheiro!\n");
        return (EXIT_SUCCESS);
    }
    
    fread(&elementos, sizeof(int), 1, f);   //Le o nº de elementos nome\nif que o ficheiro contem
    
    if(elementos != 0)  //se existem elementos
    {
        for(int i=0; i<elementos; i++)  //Cycles are gud
        {
            fread(&nif, sizeof(int), 1, f); //le para &nif da mesma maneira que usamos &nif em fscanf(), do tamanho de int, só 1, de f
            fread(&nchar, sizeof(int), 1, f); //le o nº de chars da string nome
            fread(nome, sizeof(char), nchar, f);    //lê nchar chars de f para a string nome(nome já é um ponteiro, no need for &nome)
            
            fprintf(stdout, "%s\n", nome);
            fprintf(stdout, "%i\n\n", nif);
        }
    }
    
    fclose(f);
    return (EXIT_SUCCESS);
}

