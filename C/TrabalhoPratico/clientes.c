/*
 Nome do Aluno: Bruno Miguel Almeida Junqueira
 Nº do Aluno: 21270345
 Turma Prática: P3
 */

 /* Este ficheiro de código servirá só para as funções relacionadas com o sub-menu dos Clientes
 e operações com o ficheiro respetivo.*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "functions.h"

pClientes LeFicheiroClientes(char *fc)
{
    FILE *f = fopen(fc, "r");
    pClientes c, novo, aux;
    
    c = NULL;   //Inicio um ponteiro da estrutura de Clientes vazio.
    
    if(!f)      //Se houver erro a abrir o ficheiro dos clientes, devolve uma lista vazia, termina esta função e continua a execução do programa.
    {
        fprintf(stderr, "Nao foi possivel ler o ficheiro %s!\n", fc);
        fprintf(stderr, "A lista de clientes ficara vazia!\n");
        
        return c;
    }
    
    while(1) //Ciclo infinito de leitura do ficheiro
    {
        novo = malloc(sizeof(Clientes));    //de cada vez que o ciclo corre, um novo bloco de memória é alocado.
        
        if(!novo)   //Caso exista algum erro na alocação da memória, termina a função e devolve c como se encontra
        {
            fprintf(stderr, "Erro a alocar memoria para um novo cliente!\n");
            return c;
        }
        novo->prox = novo->ant = NULL;      //ambos os ponteiro prox e ant são deixados a NULL.
        novo->aprox = NULL;                 //o mesmo de passa com o ponteiro para aprox.
        
        if(fscanf(f, " %i", &novo->nif) == EOF) //A não ser que o fscanf chegue ao fim do ficheiro e devolva EOF, o ciclo mantem-se infinito
        {
            free(novo); //caso fscanf devolva EOF, imediatamente liberta-se o bloco de memória previamente alocado...
            fclose(f);  //... fecha-se o ficheiro...
            
            return c;   //... e devolve-se o ponteiro para o inicio da lista.
        }
        
        fscanf(f, " %i", &novo->nalugueres);    //se a condição acima falhar, le-se as 2 seguintes variaveis do ficheiro
        fscanf(f, " %100[^\n]s", novo->c_nome); //formatação do input do fscanf para saltar eventuais espaços e ignorar o caracter de nova linha

        if(!c) //Se o ponteiro do inicio da lista estiver vazio...
        {
            c = novo;   //... a nova lista criada fica como primeiro elemento da lista. E novo->ant = NULL prova que é o primeiro elemento da lista.
        }
        else    //Caso contrário, ...
        {
            aux = c;    //... novo ponteiro auxiliar...
            while(aux->prox != NULL)
            {
                aux = aux->prox;    //... ciclo que corra todos os elementos da lista até chegar ao ultimo...
            }
            
            novo->ant = aux;    //... atualização do ponteiro anterior da nova estrutura para o ultimo elemento da lista...
            aux->prox = novo;   //... e atualização do ponteiro do ultimo elemento da lista para que o proximo seja o novo.
        }
        
        if(novo->nalugueres > 0)    //Antes de passar para o próximo elemento da lista, verifica se o cliente tem alugueres...
        {
            for(int i=0; i < novo->nalugueres; i++) //... se sim, inicia um ciclo que corre um nº de vezes igual ao nº de alugueres.
            {
                pAluguer alug_novo, aux_alug;   //2 novos ponteiros de memória do tipo "Estrutura de Aluguer"
                alug_novo = malloc(sizeof(Aluguer));    //Alocação de um unico bloco de memória para uma nova estrutura
                
                if(!alug_novo)  //Handle acaso erro na alocação de memória
                {
                    fprintf(stderr, "Erro ao realocar memoria para o novo aluguer!\n");
                    return c;
                }
                
                fscanf(f, " %i", &alug_novo->id);               //Leitura
                fscanf(f, " %i", &alug_novo->estado_aluguer);   //de dados
                fscanf(f, " %i", &alug_novo->diai);             //do ficheiro
                fscanf(f, " %i", &alug_novo->mesi);             //para as
                fscanf(f, " %i", &alug_novo->anoi);             //variáveis da estrutura
                
                if(alug_novo->estado_aluguer != 0)  //Se a aluguer tiver já não estiver a decorrer
                {
                    fscanf(f, " %i", &alug_novo->diaf); //Leitura da
                    fscanf(f, " %i", &alug_novo->mesf); //data do final
                    fscanf(f, " %i", &alug_novo->anof); //do aluguer
                }
                else    //Caso contrário
                {
                    alug_novo->diaf = 0;    //Deixar as
                    alug_novo->mesf = 0;    //variáveis a
                    alug_novo->anof = 0;    // 0 para fins de organização
                }
                alug_novo->prox = NULL;
                
                if(novo->aprox == NULL)     //Se for o primeiro aluguer a ser lido do ficheiro
                {
                    novo->aprox = alug_novo;    //A nova estrutura passa a ser o 1º elemento da sub-lista de alugueres
                }
                else    //Caso contrário
                {
                    aux_alug = novo->aprox; //O ponteiro auxiliar que foi criado toma o endereço de memória do 1º elemento
                    
                    while(aux_alug)   //Ciclo que avança o ponteiro auxiliar na lista até ao fim
                    {
                        aux_alug = aux_alug->prox;
                    }
                    aux_alug = alug_novo; //A nova estrutura criada e preenchida fica como ultimo elemento da sub-lista de aluguer para o cliente
                }
            }
        }
    }
}

pClientes AdicionarCliente(pClientes c)
{
    pClientes novo, aux;
    
    novo = malloc(sizeof(Clientes));    //Criação de um ponteiro para uma nova estrutura de clientes
    
    if(!novo)   //Handle básico para erro de alocação de memória
    {
        fprintf(stderr, "Erro ao alocar memoria para um novo cliente!\n");
        return c;
    }
    
    fprintf(stdout, "NIF do Cliente(9 digitos): ");
    fscanf(stdin, " %i", &novo->nif);   //NIF do novo cliente...
    
    if(novo->nif <100000000 || novo->nif>999999999) //Verificação básica para um nº de Identificação Fiscal de 9 digitos
    {
        fprintf(stderr, "Formato de NIF invalido. Introduza um NIF de 9 digitos!\n");
        free(novo);
        return c;
    }
    
    aux = c;    //Ponteiro auxiliar toma o endereço do inicio da lista...
    
    if(aux)
    {
        while(aux)    //... ciclo que corre a lista ligada dos clientes até ao final...
        {
            if(aux->nif == novo->nif)   //... que procura um NIF igual ao introduzido...
            {
                fprintf(stderr, "Ja existe um cliente com esse NIF registado!\n");
                free(novo);             //... e se o encontra, mostra uma mensagem de erro, liberta o bloco de memória alocado...

                return c;       //... e devolve o ponteiro sem qualquer modificação.
            }

            aux = aux->prox;    //Faz avançar a lista
        }
    }
    
    FILE *f = fopen("listanegra.bin", "rb");    //Abre o ficheiro da Lista Negra para procurar se o NIF está banido.
    
    int elementos = 0, nif, nchar, razao;
    char nome[NAME];
    
    fread(&elementos, sizeof(int), 1, f);   //Lê o nº de elementos previamente banidos e guarda-o em 'elementos'
    
    for(int i=0; i<elementos; i++)  //Ciclo que irá ler 'elementos' vezes as mesmas variáveis com ordem especifica...
    {
        fread(&nif, sizeof(int), 1, f);
        fread(&nchar, sizeof(int), 1, f);
        fread(nome, sizeof(char), nchar, f);
        fread(&razao, sizeof(int), 1, f);
        
        if(novo->nif == nif)    //... e de cada vez que o faz, verifica que o NIF do cliente banido corresponde ao NIF do novo cliente...
        {
            fprintf(stderr, "Esse cliente esta banido!\n"); //... e se corresponder: Mensagem de erro...
            fclose(f);  //... fecha o ficheiro...
            free(novo); //... liberta a memória previamente alocada...
            return c;   //... e devolve o ponteiro c do inicio da lista ligada sem qualquer modificação
        }
    }
    
    fprintf(stdout, "Nome do Cliente: ");
    fscanf(stdin, " %100[^\n]s", novo->c_nome); //Nome do novo cliente...
    
    aux = c;
    if(aux) //Tal e qual anteriormente, um ciclo que percorre a lista ligada dos clientes à procura de alguem com um nome igual...
    {
        while(aux->prox)    //... e um ciclo semelhante ao anterior com o mesmo objetivo.
        {
            if(strcmp(aux->c_nome, novo->c_nome) == 0)
            {
                fprintf(stderr, "Ja existe um cliente com esse nome registado!\n");
                free(novo);

                return c;   //O ponteiro inicial da lista é devolvido sem modificações.
            }

            aux = aux->prox;
        }
    }
    
    fseek(f, 0, SEEK_SET);
    fread(&elementos, sizeof(int), 1, f);
    for(int i=0; i<elementos; i++)
    {
        fread(&nif, sizeof(int), 1, f);
        fread(&nchar, sizeof(int), 1, f);
        fread(nome, sizeof(char), nchar, f);
        fread(&razao, sizeof(int), 1, f);
        
        if(novo->c_nome == nome)    //... ou então procura no mesmo ficheiro "listanegra.bin", mas agora a comparar nomes
        {
            fprintf(stderr, "Esse cliente esta banido!\n");
            fclose(f);
            free(novo);
            return c;
        }
    }
    
    novo->nalugueres = 0;   //Nenhum cliente é criado com guitarras já alugadas.
    novo->prox = NULL;      //Ambros os ponteiros de prox e ant ficam a NULL para não causar problemas de segmentação de memória mais tarde
    novo->ant = NULL;
    novo->aprox = NULL;     //Igualmente para o ponteiro do próximo aluguer
    
    if(c == NULL) //Se o ponteiro inicial estiver vazio...
    {
        c = novo;   //... o novo bloco de memória fica como primeiro elemento da lista. O ponteiro ant nulo comprovará isso.
    }
    else
    {
        aux = c;    //Novo ponteiro auxiliar...
        
        while(aux->prox)
        {
            aux = aux->prox;    //... que corre todos os elementos da lista até ao ultimo...
        }
        
        novo->ant = aux;    //... o ponteiro ant da nova estrutura aponta para o ultimo elemento da lista...
        aux->prox = novo;   //... e o ponteiro prox apontara para a nova estrutura.
    }
    
    return c;   //devolve c que estará a apontar para o endereço de memória do primeiro elemento da lista
}

pClientes RemoverCliente(pClientes c)
{
    if(!c)  //Teste se a lista está vazia
    {
        fprintf(stderr, "Nao existem clientes!\n");
        return c;
    }
    
    int nif;
    
    fprintf(stdout, "Esta prestes a remover um cliente registado.\n");
    fprintf(stdout, "Esta opcao nao o adiciona a lista negra.\n");
    fprintf(stdout, "Introduza o NIF do cliente a remover: ");
    fscanf(stdin, " %i", &nif);
    
    pClientes aux, aux2;
    pAluguer aaux, aaux2;
    aux = c;
    
    while(aux->prox && aux->nif != nif) //Ciclo que termina quando chegar ao final da lista ou encontre um cliente com o NIF introduzido
    {
        aux2 = aux;         //aux2 neste caso servirá como ponteiro para o bloco anterior a aux
        aux = aux->prox;
    }
    
    if(aux->nif != nif) //Esta condição serve para testar se o ponteiro aux correu a lista inteira, e se sim, testa se o NIF da estrutura é igual ao introduzido
    {
        fprintf(stderr, "Nao existe nenhum cliente com esse NIF na lista!\n");  //Caso não seja, mostra a mensagem de erro e devolve o ponteiro
        return c;       //do endereço inicial da lista.
    }
    
    aaux = aux->aprox;
    while(aaux) //Ciclo que irá percorrer a sub-lista de alugueres do cliente selecionado...
    {
        aaux2 = aaux->prox;
        free(aaux); //... e por cada elemento que corra, liberta o bloco de memória previamente alocado
        aaux = aaux2;
    }
    
    if(!aux->ant)    //Caso a condiçao anterior não se tenha concretizado, é porque o ciclo parou ao encontrar um NIF de um cliente igual ao introduzido
    {                       //Esta condição testa se o ponteiro auxiliar está a apontar para o primeiro elemento da lista com a ajuda do ponteiro ant
        c = aux->prox;      //Atualiza o ponteiro da lista 'c' para apontar para o segundo elemento da lista...
        free(aux);          //... liberta o bloco de memória associado ao cliente escolhido para eliminação...
    }
    else if(!aux->prox)  //Caso a condição acima não seja executada, a seguir testa se a estrutura encontrar se encontra no final da lista...
    {
        aux2->prox = NULL;      //... e nesse caso aux2, o elemento anterior a aux, modificará o seu ponteiro prox para NULL, fazendo assim com que seja o ultimo elemento...
        free(aux);              //... liberta-se o espaço de memória do ex-ultimo elemento da lista e estrutura do cliente a eliminar...
    }
    else    //Caso nenhuma das condições acima se verifique...
    {
        aux2->prox = aux->prox; //... o ponteiro prox do elemento anterior a aux apontará para o elemento a seguir a aux...
        aux->prox->ant = aux2;  //... o ponteiro ant do elemento a seguir a aux apontara para aux2...
                                //... fazendo assim com que nenhum elemento esteja a apontar para aux...
        free(aux);              //... e liberta-se o espaço de memória da estrutura do cliente a eliminar.
    }
    
    return c;   //Devolve o ponteiro para a lista atualizada.
}

void MostraCliente(pClientes c, int *diames)
{
    if(!c)  //Testa se existem clientes, caso contrário, termina de imediato a função
    {
        fprintf(stderr, "Nao existem cliente registados!\n");
        return;
    }
    
    int nif, dias_atraso;
    int cont = 0, contatra = 0, contdan = 0;
    int *data;
    
    fprintf(stdout, "NIF do Cliente a mostrar: ");
    fscanf(stdin, " %i", &nif);
    
    pClientes aux;
    pAluguer aaux;
    
    aux = c;
    
    while(aux) //Ciclo que percorre a lista ligada dos clientes inteira...
    {
        if(aux->nif == nif) //... e quando encontra um cliente com o NIF igual ao introduzido...
        {
            fprintf(stdout, "Nome: %s\n", aux->c_nome);                     //Imprime as
            fprintf(stdout, "NIF: %i\n", aux->nif);                         //informações
            fprintf(stdout, "Total de Alugueres: %i\n", aux->nalugueres);   //necessárias
            fprintf(stdout, "\nAlugueres atuais: \n");
            aaux = aux->aprox;
            while(aaux)
            {
                if(aaux->estado_aluguer == 0)
                {
                    cont++;
                    fprintf(stdout, "\tID: %i\n", aaux->id);
                    fprintf(stdout, "\tData de Inicio: %i/%i/%i\n", aaux->diai, aaux->mesi, aaux->anoi);
                    data = DataEntregaPrevista(aaux->diai, aaux->mesi, aaux->anoi, diames);
                }
                aaux = aaux->prox;
            }
            fprintf(stdout, "Numero de Alugueres Atuais: %i", cont);
            fprintf(stdout, "\nAlugueres Entregues:\n");
            aaux = aux->aprox;
            while(aaux)
            {
                if(aaux->estado_aluguer == 1)
                {
                    data = DataEntregaPrevista(aaux->diai, aaux->mesi, aaux->anoi, diames);
                    dias_atraso = DiasAtraso(aaux->diaf, aaux->mesf, aaux->anof, data, diames);
                    if(dias_atraso > 0)
                    {
                        contatra++;
                    }
                }
                else if(aaux->estado_aluguer == 2)
                {
                    contdan++;
                }
                
                aaux = aaux->prox;
            }
            fprintf(stdout, "\tAtrasados: %i\n", contatra);
            fprintf(stdout, "\tDanificados: %i\n", contdan);
            
            return;
        }
        aux = aux->prox;
    }
    
    if(!aux)
    {
        fprintf(stderr, "Nao existe nenhum cliente com esse NIF registado!\n");
        return;
    }
}

void ListaClientesAtivos(pClientes c)
{
    if(c == NULL)   //Começo logo por testar a condição de que se c estiver apontar para nada...
    {
        fprintf(stderr, "Nao exitem clientes!\n");
        return; //... termina imediatamente a execução da função.
    }
    
    pClientes aux;
    
    aux = c;
    
    while(1)    //Ciclo infinito até a condição de saída ser atingida.
    {
        fprintf(stdout, "%i\n", aux->nif);
        fprintf(stdout, "%i\n", aux->nalugueres);
        fprintf(stdout, "%s\n\n", aux->c_nome);
        
        if(aux->prox == NULL)   //Condição de saída: se não existir mais nenhum elemento a seguir na lista, termina o ciclo
        {
            break;
        }
        aux = aux->prox;    //Avança para o elemento seguinte
    }
}

void GuardaDadosClientes(char *fc, pClientes c)
{
    FILE *f = fopen(fc, "w");
    
    pAluguer aux;
    
    if(!f)  //Teste para determinar se o ficheiro foi aberto com sucesso ou não
    {
        fprintf(stderr, "Erro ao abrir o ficheiro dos Clientes para Escrita!\n");
        return; //Caso não tenha aberto com sucesso, termina de imediato a função
    }
    
    while(1)    //Ciclo infinito até atingir a condição de saída
    {
        fprintf(f, "%i ", c->nif);          //Escreve os
        fprintf(f, "%i ", c->nalugueres);   //dados para
        fprintf(f, "%s\n", c->c_nome);      //o ficheiro
        
        if(c->nalugueres > 0)   //Se o cliente já tiver alugado alguma guitarra
        {
            while(1)    //Ciclo para escrever os dados de todas as guitarras alugadas pelo cliente
            {
                fprintf(f, "%i ", c->aprox->id);
                fprintf(f, "%i ", c->aprox->estado_aluguer);
                fprintf(f, "%i ", c->aprox->diai);
                fprintf(f, "%i ", c->aprox->mesi);
                fprintf(f, "%i ", c->aprox->anoi);
                if(c->aprox->estado_aluguer != 0)   //Condição para verificar se uma dada guitarra já foi entregue ou não
                {
                    fprintf(f, "%i ", c->aprox->diaf);
                    fprintf(f, "%i ", c->aprox->mesf);
                    fprintf(f, "%i ", c->aprox->anof);
                }
                fprintf(f, "\n");
                
                if(c->aprox->prox == NULL)  //Se não existirem mais alugueres para processar
                {
                    break;  //Termina o ciclo
                }
                
                c->aprox = c->aprox->prox;  //Avança a lista de alugueres
            }
        }
        
        if(c->prox == NULL) //Condição de saída: se não existir um elemento seguinte...
        {
            break;  //... termina o ciclo.
        }
        c = c->prox;
    }
}

void ListaClientesBanidos()
{
    FILE *f = fopen("listanegra.bin", "rb");
    
    if(!f)
    {
        fprintf(stderr, "O ficheiro da listanegra (listanegra.bin) nao existe do diretorio!\n");
        return;
    }
    
    int elementos, nchar, nif, razao;
    char nome[NAME];
    
    fread(&elementos, sizeof(int), 1, f);
    
    for(int i=0; i<elementos; i++)
    {
        fread(&nif, sizeof(int), 1, f);
        fread(&nchar, sizeof(int), 1, f);
        fread(nome, sizeof(char), nchar, f);
        fread(&razao, sizeof(int), 1, f);
        
        fprintf(stdout, "Nome: %s\n", nome);
        fprintf(stdout, "NIF: %i\n", nif);
        if(razao == 1)
        {
            fprintf(stdout, "Razao: Atraso nas Entregas\n\n");
        }
        else if(razao == 2)
        {
            fprintf(stdout, "Razao: Entrega excessiva de guitarras danificadas\n\n");
        }
    }
}