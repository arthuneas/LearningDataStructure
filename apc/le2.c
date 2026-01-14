#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){

    char tipo[20];
    int n1, n2;

    fgets(tipo, 20, stdin);
    tipo[strcspn(tipo, " \n")] = '\0';

    getchar();

    if(strcmp(tipo, "SOMA") == 0 ||strcmp(tipo, "soma" == 0)){
        printf("%d", n1 + n2);

    } else if (strcmp(tipo, "SUBTRACAO") == 0 ||strcmp(tipo, "subtracao" == 0)){
        printf("%d", n1 - n2);

    } else if (strcmp(tipo, "MULTIPLICACAO") == 0 ||strcmp(tipo, "multiplicacao" == 0)){
        printf("%d", n1 * n2);
    
    } else if (strcmp(tipo, "DIVISAO") == 0 ||strcmp(tipo, "divisao" == 0)){
        printf("%d", abs(n1 / n2));

    }
    
    return 0;
}