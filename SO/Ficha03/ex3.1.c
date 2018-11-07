#include <stdio.h>
#include <stdlib.h>

int main(int argc, char** argv) {
    char buffer[25];          /* 24 chars + \0 */
    printf("\nExercicio 3.01");
    printf("\nO programa vai aguardar por uma cadeia de caracteres\n");
    scanf("%24s", buffer);   /* max = 24 chars */
    return (EXIT_SUCCESS);
}