#include <iostream>
#include <string>
#include <stdio.h>
using namespace std;

// 1 -  Faça uma função que recebe uma certa medida e ajusta ela percentualmente 
// entre dois valores mínimo e máximo e retorna esse valor
float converteSensor(int valor, int minimo, int maximo){
	int range = 0;
    int resultado = 0;
	range = maximo - minimo;
	resultado = valor * 100 / range;
	return resultado;
}
// 2 - Faça uma função que simule a leitura de um sensor lendo o 
// valor do teclado ao final a função retorna este valor
int input(){
    int valor = 0;
    printf("Insira o valor: ");
    scanf("%d", &valor);
    return valor;
}

// 3 - Faça uma função que armazena uma medida inteira qualquer 
// em um vetor fornecido. Note que como C não possui vetores 
// nativos da linguagem, lembre-se que você precisa passar o 
// valor máximo do vetor assim como a última posição preenchida
// Evite também que, por acidente, um valor seja escrito em 
// uma área de memória fora do vetor
int armazena(int *vetor, int tamanho, int ultima_posicao, int valor){
    int posicao_atual = ultima_posicao + 1;
	if (posicao_atual < tamanho){
		vetor[posicao_atual] = valor;
	}
	else{
		printf("Nao foi possivel inserir o valor, o vetor esta cheio \n");
	}
	return posicao_atual;
}

// 4 - Faça uma função que recebe um vetor com 4 posições que contém 
// o valor da distância de um pequeno robô até cada um dos seus 4 lados.
// A função deve retornar duas informações: A primeira é a direção 
// de maior distância ("Direita", "Esquerda", "Frente", "Tras") e a 
// segunda é esta maior distância.
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


// 5 - Faça uma função que pergunta ao usuário se ele deseja continuar o mapeamento e 
// retorna verdadeiro ou falso
int leComando(){
    int continuar;
    printf("Digite 0 para parar ou 1 para continuar: ");
    scanf("%d",&continuar);
    return continuar;
}

// 6 - A função abaixo (que está incompleta) vai "dirigindo" virtualmente um robô 
// e através de 4 sensores em cada um dos 4 pontos do robo ("Direita", "Esquerda", 
// "Frente", "Tras"). 
//      A cada passo, ele verifica as distâncias aos objetos e vai mapeando o terreno 
// para uma movimentação futura. 
//      Ele vai armazenando estas distancias em um vetor fornecido como parâmetro 
// e retorna a ultima posicao preenchida do vetor.
//      Esta função deve ir lendo os 4 sensores até que um comando de pare seja enviado 
//
//      Para simular os sensores e os comandos de pare, use as funções já construídas 
// nos ítens anteriores e em um looping contínuo até que um pedido de parada seja 
// enviado pelo usuário. 
//
//      Complete a função com a chamada das funções já criadas
int leSensor() {
	int value;
	std::cin >> value;
	return value;
}
void direcaoMenorCaminho(int *vetor, int maior_valor){
    string vetor_posicao[4] = {"Direita", "Esquerda", "Frente", "Tras"};
    string maior_posicao = "";
    for(int i = 0; i < 4; i++){
        if(vetor[i] > maior_valor){
            maior_valor = vetor[i];
            maior_posicao = vetor_posicao[i];
        }
    }
    printf("Movimentando para %s , distancia = %d \n", maior_posicao.c_str(), maior_valor);
}
int dirige(int *v,int maxv){
	int maxVetor = maxv;
	int *vetorMov = v;
	int posAtualVetor = 0;
	int dirigindo = 1;		
	while(dirigindo){
		// direita
		std::cout << "Direita: ";
		int medida = leSensor(); /// .. Chame a função de de leitura da medida para a "Direita"
		// medida = converteSensor(medida,0,830);
		posAtualVetor = armazena(vetorMov,maxVetor,posAtualVetor,medida);
		posAtualVetor+= 1;
		
		// esquerda
		std::cout << "Esquerda: ";
		medida = leSensor(); /// .. Chame a função de de leitura da medida para a "Direita"
		// medida = converteSensor(medida,0,830);
		posAtualVetor = armazena(vetorMov,maxVetor,posAtualVetor,medida);
		posAtualVetor+= 1;
		
		// frente
		std::cout << "Frente: ";
		medida = leSensor(); /// .. Chame a função de de leitura da medida para a "Direita"
		// medida = converteSensor(medida,0,830);
		posAtualVetor = armazena(vetorMov,maxVetor,posAtualVetor,medida);
		posAtualVetor+= 1;
		
		// tras
		std::cout << "Tras: ";
		medida = leSensor(); /// .. Chame a função de de leitura da medida para a "Direita"
		// medida = converteSensor(medida,0,830);
		posAtualVetor = armazena(vetorMov,maxVetor,posAtualVetor,medida);
		posAtualVetor+= 1;
		// Chame a função para armazenar a medida no vetor
        ///////////////////////////////////////////////////////////////////////////		
		// Repita as chamadas acima para a "Esquerda", "Frente", "Tras"
		// ................
		///////////////////////////////////////////////////////////////////////////
		dirigindo = leComando();
	}
	return posAtualVetor;
}


// O trecho abaixo irá utilizar as funções acima para ler os sensores e o movimento
// do robô e no final percorrer o vetor e mostrar o movimento a cada direção baseado 
// na maior distância a cada movimento
void percorre(int *v,int tamPercorrido){		
	int *vetorMov = v;
	int maiorDir = 0;
	
	for(int i = 0; i< tamPercorrido; i+=4){
		direcaoMenorCaminho(&(vetorMov[i]),maiorDir);
	}
}

int main(int argc, char** argv) {
	int maxVetor = 100;
	int vetorMov[maxVetor*4];
	int posAtualVet = 0;
	
	posAtualVet = dirige(vetorMov,maxVetor);
	percorre(vetorMov,posAtualVet);
	
	return 0;
}