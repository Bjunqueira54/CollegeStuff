#ifndef ALGORITMO_H
#define ALGORITMO_H

#ifdef __cplusplus
extern "C" { 
#endif

int trepa_colinas(int sol[], int *mat, int vert, int num_iter);
int trepa_colinas_probabilistico(int sol[], int *mat, int vert, int num_iter);
int recristalizacao_simulada(int sol[], int *mat, int vert, int num_iter);

#ifdef __cplusplus
}
#endif

#endif