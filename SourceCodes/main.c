#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char** argv)
{
    int nif, elementos = 0, nchar;
    char nome[50], escolha;
    FILE *f = fopen("teste.bin", "r+b");    //Abre o ficheiro binario em modo de Leitura mais escrita (para acrescentar dados sem apagar o que já lá estava)
    
    if(!f)  //Se o ficheiro não existe, como o modo r+ necessita de um ficheiro existente, faze-mos o seguinte:
    {
        fprintf(stdout, "Ficheiro nao existe!\n");  //Mensagem de erro para avisar o utilizador
        f = fopen("teste.bin", "w+b");              //Criamos um ficheiro em modo w+ (escrita + leitura), este modo pode criar ficheiros, mas se o ficheiro já existia, seria apagado
        fseek(f, 0, SEEK_SET);          //fseek para o inicio do ficheiro (em teoria o ponteiro já estará no inicio, but meh!) e escrevemos um byte de int para elementos, que é 0
        fwrite(&elementos, sizeof(int), 1, f);  //A razão para fazer isto é que assim no final quando tiver de atualizar o nº de elementos, é só reescrever por cima deste byte, assim não apago info
        fseek(f, 0, SEEK_END);      //fseek para o final para escrever info adicional (again, na teoria já estará no final, porque o ficheiro foi criado de raiz, but better safe than sorry I guess)
    }
    else    //caso o ficheiro exista
    {
        fseek(f, 0, SEEK_SET);  //fseek para o inicio do ficheiro (como abrimos no modo r+, o ponteiro está no final do ficheiro e não no inicio acho eu)
        fread(&elementos, sizeof(int), 1, f);   //lê o byte dos elementos
        fseek(f, 0, SEEK_END);  //e move o ponteiro de volta para o final
    }
    
    do
    {
        elementos++;
        fprintf(stdout, "Nome: ");
        fscanf(stdin, " %[^\n]s", nome);
        nchar = strlen(nome);   //isto é necessário porque não posso escrever uma string diretamente
        nchar++;    //adicionamos +1 a nchar porque strlen() conta os caracters no vector, mas NÃO inclui o \0 que termina a string. Por outras palavras, se não fizer isto, vou chorar no fread()
        
        fprintf(stdout, "NIF: ");
        fscanf(stdin, " %i", &nif);
        
        fwrite(&nif, sizeof(int), 1, f);    //usar &nif e não nif porque fwrite necessita de ponteiros. Estamos a escrever bytes com o tamanho de um int. Estamos só a escrever 1 int. Estamos a escrever em f
        fwrite(&nchar, sizeof(int), 1, f);  //Para não chorar em fread(), escrevemos o nº de chars que nome contem.
        fwrite(nome, sizeof(char), nchar, f);   //escrevemos nchar chars de nome[] em f
        
        fprintf(stdout, "Deseja continuar?(s ou S): ");
        fscanf(stdin, " %c", &escolha);
    }
    while(escolha == 's' || escolha == 'S');
    
    fseek(f, 0, SEEK_SET);  //voltamos ao inicio do ficheiro...
    fwrite(&elementos, sizeof(int), 1, f);  //... e escrevemos o novo "elemento" por cima do antigo, atualizando-o
    
    fclose(f);
    
    return (EXIT_SUCCESS);
}

