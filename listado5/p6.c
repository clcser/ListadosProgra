/*
Claudia Cser
Solucion propia

P6: Escriba una función recursiva que reciba una cade de caracteres, su tamaño y un caracter de referencia y 
devuelva el número de apariciones del caracter de referencia
*/


int cuentaRepeticiones(char *palabra, int tam, char c) {
    if(tam == 1)
        return 0;

    else if(palabra[0] == c) 
        return cuentaRepeticiones(palabra+1,tam-1,c) + 1;

    else
        return cuentaRepeticiones(palabra+1,tam-1,c);
}


/*
#include <stdio.h>
#include <stdlib.h>

int main() {
    int n,rep;
    char *s = NULL, c;
    scanf("%d", &n);
    getchar();

    s = malloc(n+1);
    scanf("%[^\n]", s);
    getchar();
    
    scanf("%c", &c);
    getchar();

    rep = cuentaRepeticiones(s,n,c);

    printf("El caracrter %c se repite %d veces\n",c,rep);
    
    free(s);
    s = NULL;

    return 0;
}
*/
