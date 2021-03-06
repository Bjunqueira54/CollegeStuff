/*
 Nome do Aluno: Bruno Miguel Almeida Junqueira
 Nº do Aluno: 21270345
 Turma Prática: P3
 */

/*Este ficheiro serve como ligação entre o main.c e os outros ficheiros de código.
 Contêm as estruturas e os protótipos necessários para o funcionamento do programa*/
#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#define NAME 50
#define ALUGMAX 5

#ifdef __cplusplus
extern "C" {
#endif
    
    typedef struct clientes_estrutura Clientes, *pClientes;
    typedef struct guitarras_estrutura Guitarras;
    typedef struct aluguer_estrutura Aluguer, *pAluguer;
    
    struct clientes_estrutura
    {
        char c_nome[NAME];
        int nif;
        int nalugueres;
        pClientes prox;
        pClientes ant;
        
        pAluguer aprox;
    };
    
    struct aluguer_estrutura
    {
        int id;
        int diai, mesi, anoi;
        int diaf, mesf, anof;
        int estado_aluguer;
        
        pAluguer prox;
    };

    struct guitarras_estrutura
    {
        int id;
        float ppd;
        float valor;
        int estado;
        char g_nome[NAME];
    };
    
    //Protótipos de Guitarras
    
    Guitarras* LeFicheiroGuitarras(char *fg, int *g_tam); //Funciona!
    Guitarras* AdicionarGuitarras(Guitarras *g_vec, int *g_tam); //Funciona!
    void ListarHistoricoGuitarra(pClientes c, int *diames); //Funciona!
    void ListaGuitarras(Guitarras *g_vec, int g_tam); //Funciona!
    void ListarGuitarrasAlugadas(pClientes c, Guitarras *g_vec, int g_tam); //Funciona!
    void GuardaDadosGuitarras(char *fg, Guitarras *g_vec, int g_tam); //Funciona!

    //Protótipos de Clientes
    
    pClientes LeFicheiroClientes(char *fc); //Funciona!
    pClientes AdicionarCliente(pClientes c); //Funciona!
    pClientes RemoverCliente(pClientes c); //Funciona!
    void MostraCliente(pClientes c, int *diames);   //Funciona!
    void ListaClientesAtivos(pClientes c); //Funciona!
    void ListaClientesBanidos();    //Funciona!
    void GuardaDadosClientes(char *fc, pClientes c); //Funciona!
    
    //Protótipos de Alugueres
    
    pClientes NovoAluguer(pClientes c, Guitarras *g_vec, int g_tam, int dia, int mes, int ano, int *diames);    //Funciona!
    pClientes TerminaAluguer(pClientes c, Guitarras *g_vec, int g_tam, int dia, int mes, int ano, int *diames); //Funciona!
    void ListarAlugueres(pClientes c, Guitarras *g_vec, int g_tam, int dia, int mes, int ano, int *diames);     //Funciona!
    
    //Protótipos de Outras Funções
    int* DataEntregaPrevista(int dia, int mes, int ano, int *diames);   //Funciona!
    int DiasAtraso(int dia, int mes, int ano, int *data, int *diames);  //Funciona!

#ifdef __cplusplus
}
#endif

#endif

