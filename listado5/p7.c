/*
Claudia Cser
Solucion propia

P7: Escriba una función recursiva que reciba una cadena de caracteres y su tamaño y determine si es palı́ndromo 
o no
*/


int esPalindromo(char *palabra, int tam) {
    if(tam == 1 || tam == 2)
        return 1;

    else if(palabra[0] == palabra[tam-1])
        return esPalindromo(palabra+1,tam-2);
    
    else
        return 0;
}


/*
#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, palindromo;
    char *s = NULL;

    scanf("%d",&n);
    getchar();

    s = malloc(n+1);
    scanf("%[^\n]",s);
    getchar();

    palindromo = esPalindromo(s,n);

    printf("%d\n", palindromo);
    
    free(s);
    s = NULL;

    return 0;

}
*/
