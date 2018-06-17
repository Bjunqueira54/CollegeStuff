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

int DiasAtraso(int dia, int mes, int ano, int *data, int *diames)
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
        dias_atraso = diames[mes-1] - data[0];  //.. adicionamos os restantes dias do mês aos dias de atraso...
        
        for(int i=data[1]; i<mes; i++)  //... usamos um ciclo...
        {
            dias_atraso += diames[i-1]; //... para adicionar todos os dias por cada mês de atraso...
        }
        
        dias_atraso += dia;  //... e terminamos por acrescentar os dias do mês atual que já passaram aos dias de atraso
    }
    else if(atraso == 3) //Caso 3...
    {
        if(ano - data[2] > 1)   //... se o nº de anos entre a data prevista e a data de entrega exceder 1...
        {
            int excesso_anos = ano - data[2] - 1;   //... calcula-se o nº de anos acima de 1...
            
            dias_atraso = excesso_anos * 365;   //... e multiplica-se por 365 dias o nº de anos inteiros excedidos
        }
        
        dias_atraso += (diames[mes-1] - data[0]);  //.. adicionamos os restantes dias do mês aos dias de atraso...
        
        for(int i=data[1]; i<12; i++)   //... corremos um ciclo que adiciona todos os dias de cada mes até ao final do ano...
        {
            dias_atraso += diames[i];
        }
        
        for(int i=1; i<mes; i++)    //... e outro ciclo que adiciona todos os dias de cada mês até ao mês atual...
        {
            dias_atraso += diames[i-1];
        }
        
        dias_atraso += dia; //... e termina-se a adicionar o nº de dias que já passaram do mês atual
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
                    
                    dias_atraso = DiasAtraso(dia, mes, ano, data, diames);
                    if(dias_atraso != 0)
                    {
                        fprintf(stdout, "Dias de Atraso: %i\n", dias_atraso);
                    }
                    fprintf(stdout, "\n");
                }
                lista = lista->prox;
            }
        }
        aux = aux->prox;
    }
}

pClientes TerminaAluguer(pClientes c, Guitarras *g_vec, int g_tam, int dia, int mes, int ano, int *diames)
{
    if(!c)  //Verifica se a lista está vazia...
    {
        fprintf(stderr, "Nao existem clientes na loja!\n");
        return c;   //... e se estiver, termina de imediato a função.
    }
    else if(!g_vec) //Igualmente, verfica se existem guitarras em stock...
    {
        fprintf(stderr, "Nao existem guitarras em stock!\n");
        return c;   //... e se não, termina de imediato a função.
    }
    
    int nif, id, i, dias_atraso, totaldias = 0, valor = 0, multa = 0;
    int elementos, nchar, razao, cont = 0;
    char conf;
    int *data;
    pClientes aux, aux2;
    pAluguer aaux, aaux2, banaux;
    
    fprintf(stdout, "Introduza o NIF do Cliente: ");    //Pede o nif do cliente a terminar um aluguer.
    fscanf(stdin, " %i", &nif);
    
    aux = c; //Aux fica a apontar para o inicio da lista
    
    while(aux)  //Enquanto aux existir...
    {
        if(aux->nif == nif) //... vai verificar em todos os elementos da lista se tem o nif inserido...
        {
            aaux = aux->aprox;  //... se o encontra, aaux fica a apontar para o inicio da sub-lista de alugueres desse cliente...
            break;
        }
        aux = aux->prox;    //... e se o elemento atual não tiver o nif procurado, avança a lista.
    }
    
    if(!aux)    //Caso o ciclo não tenha encontrado o nif inserido...
    {
        fprintf(stderr, "Esse cliente nao existe!\n");  //... mensagem de erro e termina imediatamente a função.
        return c;
    }
    
    fprintf(stdout, "Introduza o id da guitarra: ");    //Pede o ID da guitarra a ser entregue
    fscanf(stdin, " %i", &id);
    
    for(i=0; i<g_tam; i++)  //... inicia um ciclo que vai correr o vector das guitarras...
    {
        if(g_vec[i].id == id)   //... á procura da guitarra com o id igual ao introduzido...
        {
            break;  //... e quando o encontra, termina o ciclo e segura o valor de i
        }
    }
    
    while(aaux) //Igualmente para a procura do cliente, um ciclo que procura todos os alugueres desse cliente...
    {
        if(aaux->id == id)  //... e verifica todos os elementos da sub-lista a procura de um ID igual ao introduzido...
        {
            if(aaux->estado_aluguer == 0)   //... se o encontra, verifica o estado do elemento para ver se está a ser alugado
            {
                aaux->diaf = dia;
                aaux->mesf = mes;
                aaux->anof = ano;
                break;  //... e se sim, atualiza os valores da data final de aluguer e termina o ciclo...
            }
        }
        aaux = aaux->prox;  //... caso ambos as verificações não sejam verdadeiras, avança a lista para o próximo elemento.
    }
    
    if(!aaux)   //Caso não tenha encontrado nenhuma guitarra com o ID introduzido que esteja a ser alugada...
    {
        fprintf(stderr, "O cliente nao essa a alugar essa guitarra ou essa guitarra nao existe!\n");    //... mensagem de erro...
        return c;   //... e termina imediatamente a função
    }
    
    data = DataEntregaPrevista(aaux->diai, aaux->mesi, aaux->anoi, diames);
    dias_atraso = DiasAtraso(aaux->diaf, aaux->mesf, aaux->anof, data, diames);
    
    if(dias_atraso > 0) //se houver dias de atraso desde a data prevista até a data de entrega...
    {
        valor = g_vec[i].ppd * 7;   //... assumimos o valor máximo de um aluguer...
        
        multa = g_vec[i].ppd * dias_atraso; //... e adiciona-se cada dia extra de custo a uma multa
    }
    else    //caso contrário...
    {
        data[0] = aaux->diai;   //... os valores que são usados como data prevista passaram a ser os valores da data inicial
        data[1] = aaux->mesi;
        data[2] = aaux->anoi;
        
        dias_atraso = DiasAtraso(aaux->diaf, aaux->mesf, aaux->anof, data, diames); //chama-se a função de cálculo de dias de atraso só para calcular quantos dias passaram desde o inicio do aluguer...
        valor = g_vec[i].ppd * dias_atraso; //... e multiplica-se pelo ppd da guitarra
    }
    
    fprintf(stdout, "A guitarra esta danificada?(S/s): ");
    fscanf(stdin, " %c", &conf);
    
    if(conf == 's' || conf == 'S')   //Se a guitarra estiver danificada...
    {
        g_vec[i].estado = 2;    //... usando o valor de i que não mudou desde o ciclo, altera-se o estado da guitarra para danificada, ...
        aaux->estado_aluguer = 2;   //... o ponteiro aaux tambêm não mudou, logo no histórico de alugueres do cliente muda o estado para "Entregue Danificada"...
        
        multa += g_vec[i].valor;    //... acrescenta-se á multa o valor total da guitarra...
        
        banaux = aux->aprox;    //... (é necessário um novo ponteiro para não perder o outro)...
        
        while(banaux)   //... e vai iniciar um novo ciclo que irá correr todas as guitarras alugadas pelo cliente...
        {
            if(banaux->estado_aluguer == 2) //... á procura de todas as guitarras até á data que tenham sido entregues danificadas...
            {
                cont++; //... e se encontra uma, vai incrementar o contador...
            }
            
            if(cont > 3)    //... e se o contador for maior do que 3...
            {
                razao = 2;  //Razao: 1=Atrasos nas entregas, 2=Entregues danificadas
                
                FILE *f = fopen("listanegra.bin", "r+b");   //... vai abrir o ficheiro da lista negra no modo de leitura+escrita para adicionar uma nova entrada...
    
                if(!f)  //... se não existe, ...
                {
                    f = fopen("listanegra.bin", "w+b");  //... vai criar um novo no modo de escrita+leitura...
                    fwrite(&elementos, sizeof(int), 1, f);  //... escreve o nº de elementos banidos no ficheiro (neste caso, 0)...
                }
                else    //.. caso contrário...
                {
                    fread(&elementos, sizeof(int), 1, f);   //... le só o nº de elementos já banidos.
                }
                
                nchar = strlen(aux->c_nome);
                nchar++;    //Incremento nchar pois strlen() só lê os caracters de um vetor, não lê '\0', que é necessário
                
                fwrite(&aux->nif, sizeof(int), 1, f);
                fwrite(&nchar, sizeof(int), 1, f);
                fwrite(aux->c_nome, sizeof(char), nchar, f);
                fwrite(&razao, sizeof(int), 1, f);
                elementos++;    //Incrementa o nº de elementos banidos...
                fseek(f, 0, SEEK_SET);
                fwrite(&elementos, sizeof(int), 1, f);  //... e reescreve no inicio do ficheiro
                fclose(f);  //fecha o ficheiro
                
                if(aux->ant == NULL)    //Se o cliente está no inicio da lista...
                {
                    aux->prox->ant = NULL;  //... o campo de anterior do elemento seguinte fica nulo, ...
                    c = aux->prox;  //... fica como novo 1º elemento da lista...
                    aaux = aux->aprox;
                    while(aaux)
                    {
                        aaux2 = aaux->prox;
                        free(aaux);

                        aaux = aaux2;
                    }
                    free(aux);  //... e é libertado o espaço de memória do cliente banido, incluindo dos seus alugueres.
                }
                else if(aux->prox == NULL)
                {
                    aux->ant->prox = NULL;

                    aaux = aux->aprox;
                    while(aaux)
                    {
                        aaux2 = aaux->prox;
                        free(aaux);

                        aaux = aaux2;
                    }
                    free(aux);
                }
                else
                {
                    aux2 = aux->ant;
                    aux2->prox = aux->prox;
                    aux->prox->ant = aux2;

                    aaux = aux->aprox;
                    while(aaux)
                    {
                        aaux2 = aaux->prox;
                        free(aaux);

                        aaux = aaux2;
                    }
                    free(aux);
                }
            }
            banaux = banaux->prox;
        }
    }
    else
    {
        for(int i=0; i<g_tam; i++)  //... inicia um ciclo que vai correr o vector das guitarras...
        {
            if(g_vec[i].id == id)   //... á procura da guitarra com o id igual ao introduzido...
            {
                g_vec[i].estado = 0;    //... e quando o encontra vai mudar o seu estado para disponivel...
                break;
            }
        }
        aaux->estado_aluguer = 1;
    }
    
    aaux = aux->aprox;
    
    while(aaux)
    {
        if(aaux->estado_aluguer == 1 || aaux->estado_aluguer == 2)
        {
            data = DataEntregaPrevista(aaux->diai, aaux->mesi, aaux->anoi, diames);
            totaldias += DiasAtraso(aaux->diaf, aaux->mesf, aaux->anof, data, diames);
            
            if(totaldias > 20)
            {
                razao = 1;  //Razao: 1=Atrasos nas entregas, 2=Entregues danificadas
                
                FILE *f = fopen("listanegra.bin", "r+b");   //... vai abrir o ficheiro da lista negra
    
                if(!f)  //... se não existe, ...
                {
                    f = fopen("listanegra.bin", "wb");  //... vai criar um novo...
                    fwrite(&elementos, sizeof(int), 1, f);  //... escreve o nº de elementos banidos no ficheiro (neste caso, 0)...
                }
                else    //.. caso contrário...
                {
                    fread(&elementos, sizeof(int), 1, f);   //... le só o nº de elementos já banidos.
                }
                
                nchar = strlen(aux->c_nome);
                nchar++;    //Incremento nchar pois strlen() só lê os caracters de um vetor, não lê '\0', que é necessário
                
                fwrite(&aux->nif, sizeof(int), 1, f);
                fwrite(&nchar, sizeof(int), 1, f);
                fwrite(aux->c_nome, sizeof(char), nchar, f);
                fwrite(&razao, sizeof(int), 1, f);
                elementos++;    //Incrementa o nº de elementos banidos...
                fseek(f, 0, SEEK_SET);
                fwrite(&elementos, sizeof(int), 1, f);  //... e reescreve no inicio do ficheiro
                fclose(f);
                
                if(aux->ant == NULL)    //Se o cliente está no inicio da lista...
                {
                    aux->prox->ant = NULL;  //... o campo de anterior do elemento seguinte fica nulo, ...
                    c = aux->prox;  //... fica como novo 1º elemento da lista...
                    aaux = aux->aprox;
                    while(aaux)
                    {
                        aaux2 = aaux->prox;
                        free(aaux);

                        aaux = aaux2;
                    }
                    free(aux);  //... e é libertado o espaço de memória do cliente banido, incluindo dos seus alugueres.
                }
                else if(aux->prox == NULL)
                {
                    aux->ant->prox = NULL;

                    aaux = aux->aprox;
                    while(aaux)
                    {
                        aaux2 = aaux->prox;
                        free(aaux);

                        aaux = aaux2;
                    }
                    free(aux);
                }
                else
                {
                    aux2 = aux->ant;
                    aux2->prox = aux->prox;
                    aux->prox->ant = aux2;

                    aaux = aux->aprox;
                    while(aaux)
                    {
                        aaux2 = aaux->prox;
                        free(aaux);

                        aaux = aaux2;
                    }
                    free(aux);
                }
                
                break;
            }
        }
        aaux = aaux->prox;
    }
    
    fprintf(stdout, "Total a pagar do aluguer: %i\n", valor);
    
    if(multa > 0)
    {
        fprintf(stdout, "Multa a pagar: %i\n", multa);
    }
    
    return c;
}