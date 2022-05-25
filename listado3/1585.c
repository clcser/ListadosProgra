/*

Autor: Claudia Cser
Usuario Timus: clcser
Ejercicio resuelto de forma individual

Ej 14: 1585 Timus

*/

#include <stdio.h>
#include <string.h>

int main() {
    char c[0x12];
    int n, peng[3] = {0};
    scanf("%d",&n);
    getchar();

    for(int i = 0; i < n; i++) {
        scanf("%[^\n]", c);
        getchar();
        
        if(c[0] == 'E') peng[0]++;
        else if(c[0] == 'L') peng[1]++;
        else peng[2]++;
    }

    if(peng[0] > peng[1] && peng[0] > peng[2]) {
        printf("Emperor Penguin");

    } else if(peng[1] > peng[0] && peng[1] > peng[2]) {
        printf("Little Penguin");

    } else {
        printf("Macaroni Penguin");
    }

    return 0;
}
