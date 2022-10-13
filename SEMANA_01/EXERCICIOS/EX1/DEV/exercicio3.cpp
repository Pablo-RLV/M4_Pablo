#include <stdio.h>
#include <iostream>
void process(int tamanho){
    int vetor[tamanho];
    for(int i = 0; i < tamanho; i++){
        printf("Insira o valor: ");
        scanf("%d", &vetor[i]);
    }
    int ultimo = 0;
    ultimo = vetor[tamanho - 1];
    int maior = 0;
    for(int i = 0; i < tamanho; i++){
        if(vetor[i] > maior){
            maior = vetor[i];
        }
    }
    printf("Maior valor: %d \n", maior);
    printf("Ultimo valor: %d \n", ultimo);

}
int main(){
    int tamanho = 0;
    printf("Insira o tamanho do vetor: ");
    scanf("%d", &tamanho);
    process(tamanho);
}
