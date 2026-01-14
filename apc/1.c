#include <stdio.h>
#include <stdlib.h>
 
int main() {
 
    int num;
    int ano, mes, dia;
    int flag;
    
    ano = 0;
    mes = 0;
    dia = 0;
    
    scanf("%d", &num);
    
    ano = num / 365;
    mes = num % 365 / 30;
    dia = num - (365 * ano) - (30 * mes);
    
    printf("%d ano(s)\n", ano);
    printf("%d mes(s)\n", mes);
    printf("%d dia(s)\n", dia); 
    
 
    return 0;
}