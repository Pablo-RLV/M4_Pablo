#include <stdio.h>
float ajuste(int valor, int minimo, int maximo){
	int range = 0;
    int resultado = 0;
	range = maximo - minimo;
	resultado = valor * 100 / range;
	return resultado;
}
int main(){
    int valor = 0;
    int minimo = 0;
    int maximo = 0;
    int resultado = 0;
    printf("Digite o valor de referência: ");
    scanf("%d", &valor);
    printf("Digite o valor minimo: ");
    scanf("%d", &minimo);
    printf("Digite o valor maximo: ");
    scanf("%d", &maximo);
    resultado = ajuste(valor, minimo, maximo);
    printf("Resultado: %d", resultado, "% \n");
    return 0;
}