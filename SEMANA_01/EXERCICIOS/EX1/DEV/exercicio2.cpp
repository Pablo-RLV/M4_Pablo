#include <stdio.h>
int input(){
    int valor = 0;
    printf("Insira o valor: ");
    scanf("%d", &valor);
    return valor;
}
int main(){
    int resultado = 0;
    resultado = input();
    printf("Resultado: %d \n", resultado);
    return 0;
}
