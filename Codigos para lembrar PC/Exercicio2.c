#include <stdio.h>

int main() {
    
    float num;

    printf("Escreva um numero: ");

    scanf("%f", &num);
    
    printf("Este é o numero que você digitou: %.12f", num);
    
}