#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

char* somar(char* n1, char* n2){

}

char* subtrair(char* n1, char* n2){

}

char* multiplicar(char* n1, char* n2){

}

char* dividir(char* n1, char* n2){

}


void typemath(char* type, char* n1, char* n2){

    char* resultado;
    int soma, carry = 0;


    if (strcmp(type, "SOMA") == 0) {
        resultado = somar(n1, n2);

    } else if (strcmp(type, "SUBTRACAO") == 0) {
        resultado = subtrair(n1, n2);

    } else if (strcmp(type, "MULTIPLICACAO") == 0) {
        resultado = multiplicar(n1, n2);

    } else if (strcmp(type, "DIVISAO") == 0) {
        resultado = dividir(n1, n2);
    }

}


int main(){

    char type[30];
    char n1[100];
    char n2[100];

    scanf("%s", &type);

    scanf("%s", &n1);

    scanf("%s", &n2);

    typemath(type, n1, n2);

    return 0;
}