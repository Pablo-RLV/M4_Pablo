// 4 - Faça uma função que recebe um vetor com 4 posições que contém 
// o valor da distância de um pequeno robô até cada um dos seus 4 lados.
// A função deve retornar duas informações: A primeira é a direção 
// de maior distância ("Direita", "Esquerda", "Frente", "Tras") e a 
// segunda é esta maior distância.
#include <stdio.h>
#include <iostream>
#include <string>
using namespace std;

void process(){
    int vetor[4];
    string vetor_posicao[4] = {"Direita", "Esquerda", "Frente", "Tras"};
    for (int i = 0; i < 4; i++){
        printf("Insira o valor da %s : ", vetor_posicao[i].c_str());
        scanf("%d", &vetor[i]);
    }
    int maior_valor = 0;
    string maior_posicao = "";
    for(int i = 0; i < 4; i++){
        if(vetor[i] > maior_valor){
            maior_valor = vetor[i];
            maior_posicao = vetor_posicao[i];
        }
    }
    printf("A maior distancia e %d , na posicao %s \n", maior_valor, maior_posicao.c_str());
}

int main(){
    process();
    return 0;
}