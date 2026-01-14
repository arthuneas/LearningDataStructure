#include <stdio.h>
#include <stdlib.h>
#include <math.h>

float Delta(float a, float b, float c) {
    float delta;
    
    delta = pow(b, 2) - 4 * a * c;
    
    if (delta < 0 || a == 0){
        printf("Impossivel calcular\n");
        exit(1);
        
    } else {
        delta = sqrt(pow(b, 2) - 4 * a * c);
    
        return delta;
    }
}

float bhaskaraNeg(float a, float b, float delta) {
    float r1;

    r1 = (-b - delta) / (2 * a);
    
    return r1;
}

float bhaskaraPos(float a, float b, float delta) {
    float r2;
    
    r2 = (-b + delta) / (2 * a);
    
    return r2;
}

            
int main() {

    float a, b, c, delta;
    float r1, r2;

    scanf("%f %f %f", &a, &b, &c);
    
    delta = Delta(a, b, c);

    printf("R1 = %.5f\n", bhaskaraPos(a, b, delta));
    printf("R2 = %.5f\n", bhaskaraNeg(a, b, delta));
   
    return 0;
}