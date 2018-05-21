/*
 Nome do Aluno: Bruno Miguel Almeida Junqueira
 Nº do Aluno: 21270345
 Turma Prática: P3
 */

/*
 * Este ficheiro header existe para as funçoes da interface do menu
 * do programa.
 */

#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#ifdef __cplusplus
extern "C" {
#endif
    
    void MenuGuitarra()
    {
        int escolha = 1;
    
        while(escolha != 0)
        {
            printf("Menu de Guitarras\n");
            printf("\t1- Adicionar guitarra ao stock\n");
            printf("\t2- Mostrar historico de alugueres\n");
            printf("\t3- Listar todas as guitarras\n");
            printf("\t4- Listar guitarras alugadas\n");
            printf("\t0- Menu anterior...\n\n");
            
            printf("Escolha: ");
            fscanf(stdin, "%i", &escolha);
        
            switch(escolha)
            {
                case 1:
                    break;
                case 2:
                    break;
                case 3:
                    break;
                case 4:
                    break;
                case 0:
                    break;
                default:
                    printf("Escolha Invalida!\n");
                    break;
            }
        }
    }

    void MenuClientes()
    {
        int escolha = 1;
    
        while(escolha != 0)
        {
            printf("Menu de Clientes\n");
            printf("\t1- Novo Cliente\n");
            printf("\t2- Remover Cliente\n");
            printf("\t3- Mostrar Cliente\n");
            printf("\t4- Listar todos os clientes ativos\n");
            printf("\t5- Listar todos os clientes banidos\n");
            printf("\t0- Menu anterior...\n");
            printf("\tBanir Clientes (Passivamente)\n\n");

            printf("Escolha: ");
            fscanf(stdin, "%i", &escolha);
    
            switch(escolha)
            {
                case 1:
                    break;
                case 2:
                    break;
                case 3:
                    break;
                case 4:
                    break;
                case 5:
                    break;
                case 0:
                    break;
                default:
                    printf("Escolha Invalida!\n");
                    break;
            }
        }
    }

    void MenuAluguer()
    {
        int escolha = 1;
    
        while(escolha != 0)
        {
            printf("Menu de Aluguer\n");
            printf("\t1- Novo Aluguer\n");
            printf("\t2- Concluir Aluguer\n");
            printf("\t3- Listar Alugueres\n");
            printf("\t0- Menu anterior...\n\n");
    
            printf("Escolha: ");
            fscanf(stdin, "%i", &escolha);
        
            switch(escolha)
            {
                case 1:
                    break;
                case 2:
                    break;
                case 3:
                    break;
                case 4:
                    break;
                default:
                    printf("Escolha Invalida!\n");
                    break;
            }
        }
    }


#ifdef __cplusplus
}
#endif

#endif

