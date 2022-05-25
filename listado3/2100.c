/*
Autor: Claudia Cser
Usuario Timus: clcser
Ejercicio resuelto de forma individual

Ej 15: 2100 Timus
*/

#include <stdio.h>
#include <string.h>

int main() {
    int n, len, inv = 0;
    char names[41];

    scanf("%d",&n);
    getchar();

    for(int i = 0; i < n; i++) {
        scanf("%[^\n]",names);
        getchar();
        inv++;
        len = strlen(names);
        
        for(int i = 0; i < len; i++) {
            if(names[i] == '+') {
                inv++;
                break;
            }
        }
    }

    if(inv+2 == 13)
        printf("%d\n",(inv+3)*100);
    else 
        printf("%d\n",(inv+2)*100);

    return 0;
}
