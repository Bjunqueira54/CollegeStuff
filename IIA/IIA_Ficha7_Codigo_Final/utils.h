#ifndef UTILS_H
#define UTILS_H

#ifdef __cplusplus
extern "C" { 
#endif

int* init_dados(char *nome, int *n, int *iter);
void gera_sol_inicial(int *sol, int v);
void escreve_sol(int *sol, int vert);
void substitui(int a[], int b[], int n);
void init_rand();
int random_l_h(int min, int max);
float rand_01();

#ifdef __cplusplus
}
#endif

#endif