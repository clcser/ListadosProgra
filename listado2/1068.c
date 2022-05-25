/*
Autor: Claudia Cser
Usuario Timus: clcser
Ejercicio resuelto de manera individual

Ej 13: 1068 timus
*/

int main() {
    int n;
    scanf("%d", &n);

    if(n > 0) printf("%d", (n*(n+1)/2));
    else if(n < 0) printf("%d", (n*-(n-1)/2)+1);
    else printf("-1");

    return 0;
}


