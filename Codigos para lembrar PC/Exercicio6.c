#include <stdio.h>

int main() {
    
    float celsius;
    float calculo;

    printf("Escreva os graus celcius atuais: ");
    scanf("%f", &celsius);
    
     calculo = celsius * (9.0/5.0) + 32.0;
    printf("A temperatura se tu fosse para os estados unidos seria: %.2f", calculo);
}