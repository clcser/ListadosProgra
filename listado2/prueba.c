#include <stdio.h>

int main() {
    int a, n = 0;
    scanf("%d", &a);
    if (a < 0) {
        for (int i = 1; i >= a; --i)
            n += 1;
        printf("%d\n",n);
    } else if(a == 0)
        printf("1\n");
    else {
        for(int i = 1; i <= a; ++i)
            n += i;
        printf("%d\n",n);
    }
    return 0;
}
