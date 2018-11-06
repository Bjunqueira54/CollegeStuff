/*
 Nome do Aluno: Bruno Miguel Almeida Junqueira
 Nº do Aluno: 21270345
 Turma Prática: P3
 */

 /* Este ficheiro de código servirá só para as funções relacionadas com o sub-menu das Guitarras
 e operações com o ficheiro respetivo.*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "functions.h"

void VerificaEstado(int est)    //Função rápida para escrever o estado a guitarra em vez de um número.
{
    if(est == 0)    //De acordo com o enunciado: 0-Disponivel, 1-Alugada, 2-Danificada.
    {
        fprintf(stdout, "Disponivel\n\n");
    }
    else if(est == 1)
    {
        fprintf(stdout, "Alugada\n\n");
    }
    else    //Mesmo não estando a espera de outros valores sem ser 0, 1 e 2, deixo aqui um "else" só para o caso de qualquer tipo de modificação
    {       //exterior no ficheiro das guitarras devolve como guitarra danificada.
        fprintf(stdout, "Danificada\n\n");
    }
}

Guitarras* LeFicheiroGuitarras(char *fg, int *g_tam)
{
    FILE *f = fopen(fg, "r");
    
    Guitarras *g_vec;   //Ponteiro para o vetor dinâmico
    
    int i = 0;
    
    if(!f)  //Caso o ficheiro não seja aberto...
    {
        fprintf(stderr, "Erro ao abrir o ficheiro das Guitarras para Leitura!\n");
        (*g_tam) = 0;   //... o tamanho é reposto a 0...
        g_vec = NULL;   //... o ponteiro é nulificado...
        return g_vec;   //... e devolvido.
    }
    
    g_vec = malloc(sizeof(Guitarras));  //Bloco inicial de memória do vetor
    
    if(!g_vec)  //Caso exista algum erro a alocar memória...
    {
        fprintf(stderr, "Erro ao alocar memoria!\n");   //... mensagem de erro...
        (*g_tam) = 0;   //... tamanho volta a 0...
        return NULL;    //... e devolve NULL
    }
    
    while(1)    //Ciclo infinito até a condição de saída se verificar
    {
        if(fscanf(f, "%i", &g_vec[i].id) == EOF)    //Condição de saída: se fscanf devolver EOF
        {
            g_vec = realloc(g_vec, i * sizeof(Guitarras));  //Muda o tamanho o vetor para i, onde i = tamanho do vetor
            
            if(!g_vec)  //Se existir algum problema com a realocação de memória...
            {
                fprintf(stderr, "Erro ao realocar memoria para o vetor!\n");    //... mensagem de erro...
                return g_vec;   //... mas devolve g_vec em vez de NULL porque o vetor pode já estar habitado.
            }
            i--;        //Decrementa i, a razão sendo a linha de código mais abaixo.
            break;
        }
        fscanf(f, " %f", &g_vec[i].ppd);                //Leitura
        fscanf(f, " %f", &g_vec[i].valor);              //dos dados
        fscanf(f, " %i", &g_vec[i].estado);             //do ficheiro
        fscanf(f, " %100[^\n]s", g_vec[i].g_nome);      //para a estrutura
        
        i++;    //Incrementa i para o próximo ciclo.
        g_vec = realloc(g_vec, (i+1) * sizeof(Guitarras));  //Incrementa o tamanha do vetor por 1
        if(!g_vec)
        {
            fprintf(stderr, "Erro ao realocar memoria para o vetor!\n");
            i--;
            (*g_tam) = i;
            return g_vec;
        }
    }
    
    (*g_tam) = i+1; //Tamanho será o número de vezes que o ciclo correu +1 devido a i começar em zero.
    fclose(f);
    return g_vec;   //devolve o ponteiro para o inicio do vetor.
}

void ListaGuitarras(Guitarras *g_vec, int g_tam)
{
    if(g_vec == NULL)   //Acaso o vetor esteja vazio...
    {
        fprintf(stderr, "O vetor esta vazio!\n");
        return; //... imediatamente termina a execução desta função
    }
    
    for(int i=0; i<g_tam; i++)  //Ciclo que corre o vetor inteiro até ao ultimo elemento
    {
        fprintf(stdout, "ID: %i\n", g_vec[i].id);                   //Escrita
        fprintf(stdout, "Nome: %s\n", g_vec[i].g_nome);             //dos dados
        fprintf(stdout, "Preco por Dia: %.2f\n", g_vec[i].ppd);     //para o
        fprintf(stdout, "Valor: %.2f\n", g_vec[i].valor);           //Standard Output
        fprintf(stdout, "Estado: ");
        VerificaEstado(g_vec[i].estado);                            //A função de Verificar o estado só para não mostrar numeros
    }
}

Guitarras* AdicionarGuitarras(Guitarras *g_vec, int *g_tam)
{
    
    int newTam = (*g_tam);  //Necessito de uma nova variavel de tamanho para mais a frente
    int i=0;
    
    newTam++;   //Como o vetor tem de ser incrementado por 1 para a nova guitarra, incremento o novo tamanho
    
    g_vec = realloc(g_vec, sizeof(Guitarras) * newTam); //Aumento o vetor das guitarras com o novo tamanho
    
    if(!g_vec)
    {
        fprintf(stderr, "Erro ao realocar memoria para o vetor!\n");
        return g_vec;
    }
    
    fprintf(stdout, "ID da Guitarra: ");
    fscanf(stdin, "%i", &g_vec[*g_tam].id); //ID da nova guitarra...
    while(i<(*g_tam))   //... e um ciclo básico e rápido a verificar se esse ID já existe no vetor existente
    {
        if(g_vec[*g_tam].id == g_vec[i].id) //Se encontra um ID igual, mostra uma mensagem de erro...
        {
            fprintf(stderr, "Ja existe uma guitarra com esse numero de ID!\n");
            g_vec = realloc(g_vec, sizeof(Guitarras) * (*g_tam));   //... decrementa o tamanho do vetor de volta a como estava inicialmente...
            if(!g_vec)
            {
                fprintf(stderr, "Erro ao realocar memoria para o vetor!\n");
                return g_vec;
            }
            return g_vec;   //... e devolve o ponteiro da primeira posição do vetor
        }
        i++;
    }
    
    fprintf(stdout, "Nome da Guitarra: ");
    fscanf(stdin, " %100[^\n]s", g_vec[*g_tam].g_nome);     //Leitura dos
    fprintf(stdout, "Preco por Dia: ");
    fscanf(stdin, " %f", &g_vec[*g_tam].ppd);               //novos dados da
    fprintf(stdout, "Valor da Guitarra: ");
    fscanf(stdin, " %f", &g_vec[*g_tam].valor);             //nova guitarra
    g_vec[*g_tam].estado = 0;   //Nenhuma Guitarra que esteja a ser adicionada ao stock está imediatamente alugada ou danificada.
    
    (*g_tam) = newTam;  //Atualização do tamanho do vetor.
    
    return g_vec;   //Devolve o ponteiro da primeira posição do vetor
}

void GuardaDadosGuitarras(char *fg, Guitarras *g_vec, int g_tam)
{
    FILE *f = fopen(fg, "w");
    
    if(!f)  //Handle básico da falha de abertura do ficheiro
    {
        fprintf(stderr, "Erro ao abrir o ficheiro das Guitarras para Escrita!\n");
        return;
    }
    
    for(int i=0; i<g_tam; i++)  //Como se está a trabalhar com um vetor, um ciclo for é justificado
    {
        fprintf(f, "%i ", g_vec[i].id);         //Escrita dos
        fprintf(f, "%.2f ", g_vec[i].ppd);      //dados de cada guitarra
        fprintf(f, "%.2f ", g_vec[i].valor);    //para o ficheiro
        fprintf(f, "%i ", g_vec[i].estado);     //aberto
        fprintf(f, "%s\n", g_vec[i].g_nome);    //o nome da guitarra em ultimo com o caracter de nova linha
    }
    
    free(g_vec);    //Liberto o bloco de memória alocado na criação do vetor
}

void ListarGuitarrasAlugadas(pClientes c, Guitarras *g_vec, int g_tam)
{
    if(!g_vec)  //Se o vetor estiver vazio, termina imediatamente a função.
    {
        fprintf(stderr, "Nao existem guitarras em stock!\n");
        return;
    }
    else if(!c) //Igualmente para a lista ligada dos clientes
    {
        fprintf(stderr, "Nao existem clientes registados na loja!\n");
        return;
    }
    
    pClientes aux;  //Ponteiro auxiliar...
    aux = c;    //... iguala-do a c
    pAluguer aaux;
    
    while(aux)  //Ciclo que irá correr a lista ligada inteira...
    {
        aaux = aux->aprox;  //... e em cada elemento...
        
        while(aaux) //... irá correr a sua sub-lista de alugueres...
        {
            if(aaux->estado_aluguer == 0)   //... à procura de guitarras custo estado de aluguer seja esteja a Decorrer...
            {
                for(int i=0; i<g_tam; i++)  //... e quando encontra, irá correr o vetor das guitarras à procura de uma guitarra com ID igual ao do elemento da sub-lista...
                {
                    if(g_vec[i].id == aaux->id) //... e quando o encontrar...
                    {
                        fprintf(stdout, "Nome da Guitarra: %s\n", g_vec[i].g_nome);     //... irá imprimir todos
                        fprintf(stdout, "ID da Guitarra: %i\n", g_vec[i].id);           //os dados
                        fprintf(stdout, "Preco por Dia: %5.2f\n", g_vec[i].ppd);        //necessários
                        fprintf(stdout, "Valor da Guitarra: %5.2f\n", g_vec[i].valor);  //sobre a guitarra
                        fprintf(stdout, "Nome do Cliente a alugar: %s\n", aux->c_nome); //que está atualmente
                        fprintf(stdout, "NIF do Cliente: %i\n\n", aux->nif);            //a ser alugada
                        
                    }
                }
            }
            aaux = aaux->prox;  //Avança a sub-lista de alugueres
        }
        
        aux = aux->prox;    //Avança a lista de clientes.
    }
}

void ListarHistoricoGuitarra(pClientes c, int *diames)
{
    if(!c)  //Se não existirem clientes...
    {
        fprintf(stderr, "Nao existem clientes registados para terem alugado uma guitarra\n");
        return; //... termina de imediato a função
    }
    
    fprintf(stdout, "Introduza o ID da guitarra: ");
    int id, dias_atraso;
    int *data;
    fscanf(stdin, " %i", &id);
    
    pClientes aux;
    pAluguer aaux;
    
    aux = c;
    
    while(aux)  //Ciclo que percorre a lista ligada dos clientes...
    {
        if(aux->nalugueres > 0) //... à procura de clientes que tenham um histórico de alugueres...
        {
            aaux = aux->aprox;

            while(aaux) //... e inicia um ciclo que corre a sub-lista dos alugueres por cliente...
            {
                if(aaux->id == id)  //... e sempre que encontra um elemento dessa sub-lista com o ID igual ao pedido pelo utilizador...
                {
                    if(aaux->estado_aluguer == 1 || aaux->estado_aluguer == 2)  //... verifica se o aluguer já terminou...
                    {
                        fprintf(stdout, "Nome do Cliente: %s\n", aux->c_nome);      //... e se já, irá imprimir a informação necessária
                        fprintf(stdout, "Data de Inicio: %i/%i/%i\n", aaux->diai, aaux->mesi, aaux->anoi);  //para demonstrar o histórico de algueres da guitarra
                        fprintf(stdout, "Data de Entrega: %i/%i/%i\n", aaux->diaf, aaux->mesf, aaux->anof);

                        data = DataEntregaPrevista(aaux->diai, aaux->mesi, aaux->anoi, diames); //Calcula a data prevista da entrega com base na data de inicio...
                        dias_atraso = DiasAtraso(aaux->diaf, aaux->mesf, aaux->anof, data, diames); //... e calcula se existem dias de atraso com base na data de fim de aluguer

                        if(dias_atraso > 0) //Acaso existam dias de atraso nesse aluguer...
                        {
                            fprintf(stdout, "Dias de Atraso: %i\n\n", dias_atraso); //... imprime-os no output
                        }

                        fprintf(stdout, "\n");
                    }
                }
                aaux = aaux->prox;  //Faz avançar a sub-lista dos alugueres
            }
        }
        aux = aux->prox;    //Faz avançar a lista dos clientes
    }
}