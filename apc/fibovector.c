#include <stdio.h>
#include <stdlib.h>

define NUM 200

void fibo(int n){

    if (n < 0) {
        printf("0\n");
    } else if (n <= 2) {
        printf("1\n");
    }

    int soma_numero, resto, digito;
    int anterior[NUM] = {0}
    int antes_anterior[NUM] = {0}
}



int main() {

    int n;

    printf("digite um numero para fibo");
    scanf("%d", &n);

    fibo(n);

    return 0;
}