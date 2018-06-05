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

int* DataEntregaPrevista(int dia, int mes, int ano, int *diames)
{
    int *data;
    
    data = malloc(sizeof(int) * 3);
    
    data[0] = dia;
    data[1] = mes;
    data[2] = ano;
    
    if(data[0] + 7 > diames[data[1] - 1]) //Se o dia mais os 7 dias do alguer ultrapassar o nº de dias máximo do mês atual em diasmes
    {
        data[0] += 7;   //soma os 7 dias de aluguer ao dia
        data[0] -= diames[data[1] - 1]; //subtrai os dias do mês atual
        data[1]++;  //Incrementa o mês por 1
    }
    else
    {
        data[0] += 7;
    }
    if(data[1] > 12)    //Se o mês por alguma razão for maior que 13...
    {
        data[1] -= 12;  //... subtrai 12 meses de volta a 1...
        data[2]++;  //... e incrementa o ano.
    }
    
    return data;
}

int DiasAtraso(int dia, int mes, int ano, int *diames, int *data)
{
    int dias_atraso, atraso = 0; //Variável a devolver com dias de atraso e variável de controlo
    
    if(ano - data[2] > 0) //Se o ano da data atual for superior ao ano da data prevista...
    {
        atraso = 3; //... a variável de controlo é atualizada para o caso 3 - Ano aumentou
    }
    else if(mes - data[1] > 0)  //Se o mes da data atual for superior ao mes da data prevista...
    {
        atraso = 2; //... a variável de controlo é atualizada para o caso 2 - Mês Aumentou
    }
    else if(dia - data[0] > 0)  //Se o dia da data atual é maior que o dia previsto para a entrega...
    {
        atraso = 1; //... a variável de controlo é atualizada para o caso 2 - Dia Aumentou
    }
    
    if(atraso == 0)  //Se a variável de controlo se mantiver a 0...
    {
        dias_atraso = 0;    //... é porque a data prevista para a entrega do aluguer ainda não foi ultrapassada
    }
    else if(atraso == 1) //Caso 1...
    {
        dias_atraso = dia - data[0];    //... basta subtrair os dias da data atual pelos dias da data prevista para obter os dias de atraso
    }
    else if(atraso == 2) //Caso 2...
    {
        dias_atraso = diames[data[1]-1] - data[0];  //.. adicionamos os restantes dias do mês previsto aos dias de atraso...
        
        if(mes - data[1] > 1)
        {
            for(int i=data[1]; i<mes; i++)  //... usamos um ciclo...
            {
                dias_atraso += diames[i-1]; //... para adicionar todos os dias por cada mês de atraso...
            }
        }
        dias_atraso += dia;  //... e terminamos por acrescentar os dias do mês atual que já passaram aos dias de atraso
    }
    else if(atraso == 3) //Caso 3...
    {
        dias_atraso = diames[data[1]-1] - data[0];    //... adicionamos os dias restantes do mês previsto...
        
        for(int i=(data[1]); i<12; i++)   //... adicionamos todos os dias de cada mês até ao final do ano...
        {
            dias_atraso += diames[i];
        }
        
        if(ano - data[2] > 1)   //... testamos se existem anos inteiros que passaram após a data prevista...
        {
            for(int i=(data[2]+1); i<ano; i++)  //... e se sim, adicionamos 365 dias por cada ano inteiro que passou...
            {
                dias_atraso += 365;
            }
        }
        
        for(int i=1; i<mes; i++)    //... de seguida adiciona-se cada mês por inteiro que passou desde o inicio do novo ano...
        {
            dias_atraso += diames[i-1]; //... mas não o mês atual...
        }
        
        dias_atraso += dia; //... e finalmente adiciona-se todos os dias do mês atual que já passaram, incluindo o atual.
    }
    
    return dias_atraso; //devolve o nº de dias de atraso
}

pClientes NovoAluguer(pClientes c, Guitarras *g_vec, int g_tam, int dia, int mes, int ano, int *diames)
{
    if(!c)  //Se não existirem clientes na loja...
    {
        fprintf(stderr, "Nao existem clientes registados para alugar guitarras!\n");
        return c;   //... a função termina imediatamente
    }
    if(!g_vec)  //Igualmente para as guitarras
    {
        fprintf(stderr, "Nao existem guitarras para serem alugadas!\n");
        return c;
    }
    
    pAluguer novo = malloc(sizeof(Aluguer));    //Novo bloco de memóra para um novo aluguer
    
    pClientes aux;
    
    int id, i, nif;
    
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

    novo->diai = dia;
    novo->mesi = mes;
    novo->anoi = ano;
    
    novo->anof = novo->mesf = novo->diaf = 0;   //Dia\Mês\Ano do fim do aluguer ficam a 0 para organização de informação
    novo->prox = NULL;
    novo->id = g_vec[i].id;                     //A estrutura de aluguer tẽm um campo para o ID da guitarra alugada
    novo->estado_aluguer = 0;
    
    int *data = DataEntregaPrevista(dia, mes, ano, diames);
    
    fprintf(stdout, "Data de Entrega: %i/%i/%i\n", data[0], data[1], data[2]);  //Mostra a data limite do aluguer.
    
    if(aux->aprox == NULL)  //Se o cliente não tiver nenhum aluguer associado a sua conta...
    {
        aux->aprox = novo;  //... o novo aluguer fica como 1º elemento da sua sub-lista de aluguer
    }
    else    //Caso contrário...
    {
        pAluguer alug_aux;  //...novo ponteiro auxiliar...
        
        alug_aux = aux->aprox;  //... que ficará com o endereço de memória do 1º elemento da sub-lista
        while(alug_aux->prox)   //... e entra num ciclo que avança o ponteiro até ao final da lista...
        {
            alug_aux = alug_aux->prox;
        }
        alug_aux->prox = novo;  //... onde o novo aluguer criado ficará como ultimo elemento
    }
    
    aux->nalugueres += 1;    //Incrementa o nº de alugueres que do cliente
    
    return c;   //devolve o endereço do inicio da lista de clientes atualizada
}

void ListarAlugueres(pClientes c, Guitarras *g_vec, int g_tam, int dia, int mes, int ano, int *diames)
{
    if(!c)  //Se não existirem clientes...
    {
        fprintf(stderr, "Nao existem clientes na loja!\n");
        return; //Termina de imediato a função
    }
    
    int i, dias_atraso;
    int *data;
    
    pAluguer lista; //Cria dois ponteiros para auxiliar nas listas
    pClientes aux;
    
    aux = c; //Aux fica com o endereço do c, logo, o endereço do 1º elemento
    
    while(aux)
    {
        lista = aux->aprox;
        
        if(lista)
        {
            while(lista)
            {
                if(lista->estado_aluguer == 0)
                {
                    fprintf(stdout, "Nome do Cliente: %s\n", aux->c_nome);
                    fprintf(stdout, "NIF do Cliente: %i\n", aux->nif);
                    fprintf(stdout, "ID da Guitarra: %i\n", lista->id);
                    fprintf(stdout, "Data de Inicio: %i/%i/%i\n", lista->diai, lista->mesi, lista->anoi);
                    data = DataEntregaPrevista(lista->diai, lista->mesi, lista->anoi, diames);
                    fprintf(stdout, "Data Prevista para a Entrega: %i/%i/%i\n", data[0], data[1], data[2]);
                    
                    dias_atraso = DiasAtraso(dia, mes, ano, diames, data);
                    
                    if(dias_atraso != 0)
                    {
                        fprintf(stdout, "Dias de Atraso: %i\n\n", dias_atraso);
                    }
                    else
                    {
                        printf("\n\n");
                    }
                }
                lista = lista->prox;
            }
        }
        aux = aux->prox;
    }
}

pClientes TerminaAluguer(pClientes c, Guitarras *g_vec, int g_tam, int dia, int mes, int ano, int *diames)
{
    int id, i, dias_atraso;
    int *data = DataEntregaPrevista(dia, mes, ano, diames);
    char op;
    
    dias_atraso = DiasAtraso(dia, mes, ano, diames, data);
    
    pClientes aux;
    pAluguer lista;
    
    fprintf(stdout, "Introduza o ID da Guitarra: ");
    fscanf(stdin, " %i", &id);
    
    for(i=0; i<g_tam; i++)
    {
        if(g_vec[i].id == id)
        {
            if(g_vec[i].estado != 1)
            {
                fprintf(stderr, "Essa guitarra nao esta a ser alugada!\n");
                return c;
            }
            else
            {
                break;
            }
        }
    }
    if(g_vec[i].id != id) //se chegou ao fim do vetor e não um ID igual ao introduzido...
    {
        fprintf(stderr, "Essa guitarra nao existe!\n"); //... mostra uma mensagem de erro...
        return c;   //... e devolve o ponteiro para o inicio da lista sem haver modificações.
    }
    
    aux = c;
    
    while(aux)
    {
        lista = aux->aprox;
        
        while(lista)
        {
            if(lista->id == id);
            {
                lista->diaf = dia;
                lista->mesf = mes;
                lista->anof = ano;
                
                fprintf(stdout, "A Guitarra esta danificada?(S ou s para Sim): ");
                fscanf(stdin, " %c", &op);
                
                if(op == 'S' || op == 's')
                {
                    lista->estado_aluguer = 2;
                    aux->danificadas += 1;
                    
                    for(i=0 ;i<g_tam ;i++)
                    {
                        if(g_vec[i].id == id)
                        {
                            g_vec[i].estado = 2;
                            break;
                        }
                    }
                }
                else
                {
                    lista->estado_aluguer = 1;
                    
                    for(i=0 ;i<g_tam ;i++)
                    {
                        if(g_vec[i].id == id)
                        {
                            g_vec[i].estado = 0;
                            break;
                        }
                    }
                }
                
                if(dias_atraso > 0)
                {
                    aux->atraso = dias_atraso;
                }
                
                return c;
            }
            lista = lista->prox;
        }
        aux = aux->prox;
    }

    if(!aux)
    {
        fprintf(stderr, "Erro ao encontrar um cliente a alugar essa guitarra!\n");
        return c;
    }
}