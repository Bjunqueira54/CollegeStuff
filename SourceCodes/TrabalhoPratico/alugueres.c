/*
 Nome do Aluno: Bruno Miguel Almeida Junqueira
 Nº do Aluno: 21270345
 Turma Prática: P3
 */

 /* Este ficheiro de código servirá só para as funções relacionadas com o sub-menu dos Alugueres
 e operações com o ficheiro respetivo.*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "functions.h"

pClientes NovoAluguer(pClientes c, Guitarras *g_vec, int g_tam)
{
    if(!c)
    {
        fprintf(stderr, "Nao existem clientes registados para alugar guitarras!\n");
        return c;
    }
    if(!g_vec)
    {
        fprintf(stderr, "Nao existem guitarras para serem alugadas!\n");
        return c;
    }
    
    pAluguer novo = malloc(sizeof(Aluguer));    //Novo bloco de memóra para um novo aluguer
    
    pClientes aux, alugada;
    
    int id, i, nif;
    int diames[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};  //Vetor com o número de dia por mes
    
    fprintf(stdout, "Introduza o NIF do cliente: ");
    fscanf(stdin, " %i", &nif); //NIF do cliente a alugar a guitarra
    
    aux = c;
    
    while(aux->prox != NULL && aux->nif != nif) //Ciclo que vai correr todos os elementos da lista de clientes
    {                                           //a procura de um NIF igual ao introduzido
        aux = aux->prox;
    }
    if(!aux->prox && aux->nif != nif)   //Se quando chegar ao final e não tiver encontrado um NIF igual...
    {
        fprintf(stderr, "Esse cliente nao existe!\n");  //... mostra uma mensagem de erro...
        free(novo); //... liberta o bloco de memória criado para o novo aluguer...
        return c;   //... e devolve o ponteiro para o inicio da lista sem haver modificações.
    }
    
    if(aux->nalugueres == ALUGMAX || aux->nalugueres > ALUGMAX) //Testa a condição se o cliente já atingiu o limite de alugueres, se sim...
    {
        fprintf(stderr, "O cliente atingiu o limite máximo de alugueres!\n");   //... mostra uma mensagem de erro...
        free(novo); //... liberta o bloco de memória criado para o novo aluguer...
        return c;   //... e devolve o ponteiro para o inicio da lista sem haver modificações.
    }
    
    fprintf(stdout, "Introduza o ID da guitarra a alugar: ");
    fscanf(stdin, " %i", &id);  //ID da guitarra a ser alugada
    
    for(i=0; i<g_tam; i++)          //Um ciclo com o mesmo objectivo do anterior
    {
        if(g_vec[i].id == id)       //Procura no vetor de guitarras se existe uma guitarra com o ID introduzido
        {
            if(g_vec[i].estado == 0)    //Se a guitarra estiver "Disponivel"...
            {
                if(g_vec[i].valor > 500)
                {
                    fprintf(stderr, "Falta implementar o algoritmo!\n");
                    break;
                }
                else
                {
                    g_vec[i].estado = 1;    //... muda o estado da guitarra para "Alugada"
                    break;
                }
            }
            else if(g_vec[i].estado == 1)   //Se a guitarra já estiver alugada...
            {
                fprintf(stderr, "A guitarra ja esta a ser alugada!\n");    //... mostra uma mensagem de erro...
                free(novo); //... liberta o bloco de memória criado para o novo aluguer...
                return c;   //... e devolve o ponteiro para o inicio da lista sem haver modificações.
            }
            else    //Caso nenhuma das outra condições se verifique...
            {
                fprintf(stderr, "A guitarra está danificada!\n");    //... mostra uma mensagem de erro...
                free(novo); //... liberta o bloco de memória criado para o novo aluguer...
                return c;   //... e devolve o ponteiro para o inicio da lista sem haver modificações.
            }
        }
    }
    
    if(g_vec[i].id != id) //se chegou ao fim do vetor e não um ID igual ao introduzido...
    {
        fprintf(stderr, "Essa guitarra nao existe!\n"); //... mostra uma mensagem de erro...
        free(novo); //... liberta o bloco de memória criado para o novo aluguer...
        return c;   //... e devolve o ponteiro para o inicio da lista sem haver modificações.
    }
    
    fprintf(stdout, "Introduza a data de Inicio do aluguer\n");
    fprintf(stdout, "\tMes: ");
    fscanf(stdin, " %i", &novo->mesi);  //Mês do inicio do aluguer da guitarra
    if(novo->mesi < 1 || novo->mesi > 12)   //Se o mês introduzido não for de Janeiro a Dezembro
    {
        fprintf(stderr, "Mes invalido!\n"); //... mostra uma mensagem de erro...
        free(novo); //... liberta o bloco de memória criado para o novo aluguer...
        return c;   //... e devolve o ponteiro para o inicio da lista sem haver modificações.
    }
    
    fprintf(stdout, "\tDia: ");
    fscanf(stdin, " %i", &novo->diai);  //Dia do inicio do aluguer da guitarra
    if(novo->diai < 1 || novo->diai > diames[novo->mesi - 1])   //Se o mês introduzido não for de 1 ao dia introduzido no vetor diames[]...
    {
        fprintf(stderr, "Dia invalido para o mes introduzido!\n");  //... mostra uma mensagem de erro...
        free(novo); //... liberta o bloco de memória criado para o novo aluguer...
        return c;   //... e devolve o ponteiro para o inicio da lista sem haver modificações.
    }
    
    fprintf(stdout, "\tAno: ");
    fscanf(stdin, " %i", &novo->anoi);  //Ano do inicio do aluguer da guitarra
    
    novo->anof = novo->mesf = novo->diaf = 0;   //Dia\Mês\Ano do fim do aluguer ficam a 0 para organização de informação
    novo->prox = NULL;
    novo->id = g_vec[i].id;                     //A estrutura de aluguer tẽm um campo para o ID da guitarra alugada
    novo->estado_aluguer = 0;
    
    int dia, mes, ano;  //Variáveis para mostrar a data do fim de aluguer
    
    dia = novo->diai;
    mes = novo->mesi;
    ano = novo->anoi;
    
    if(dia + 7 > diames[mes-1]) //Se o dia mais os 7 dias do alguer ultrapassar o nº de dias máximo do mês atual em diasmes
    {
        dia += 7;   //soma os 7 dias de aluguer ao dia
        dia -= diames[mes - 1]; //subtrai os dias do mês atual
        mes++;  //Incrementa o mês por 1
    }
    else
    {
        dia += 7;
    }
    if(mes > 12)    //Se o mês por alguma razão for maior que 13...
    {
        mes -= 12;  //... subtrai 12 meses de volta a 1...
        ano++;  //... e incrementa o ano.
    }
    
    fprintf(stdout, "Data de Entrega: %i/%i/%i\n", dia, mes, ano);  //Mostra a data limite do aluguer.
    
    aux->aprox = novo;  //Atualiza o ponteiro da lista de alugueres do cliente
    aux->nalugueres += 1;    //Incrementa o nº de alugueres que o cliente têm
    
    return c;
}