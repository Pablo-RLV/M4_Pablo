// Faça uma função que lê os valores 0 e 1, ficando em loop até que o valor 0 seja lido
#include <iostream>
int leComando(){
    int input;
    printf("Digite 0 para parar ou 1 para continuar: ");
    scanf("%d",&input);
    return input;
}

int main() {
    int input = leComando();
    while(input== 1){
        printf("True \n");
        input = leComando();
    }
    printf("False \n");
    return 0;
}
