int porta_sensor = 8;
int porta_buzzer = 3;
int botao1 = 9;
int botao2 = 10;
int vetor_leds[4] = {4, 5, 6, 7};
int valor_sensor = 0;
int binario[4]={0,0,0,0};
int vetor_binario[4] = {0, 0, 0, 0};
int i = 0;
int f = 0;
int vetor_frequencia[100];
void setup() {
  Serial.begin(115200);
  for(int portas=0; portas <= 3; portas++){
    pinMode(vetor_leds[portas], OUTPUT);
  }
  pinMode(porta_sensor, INPUT);
  pinMode(porta_buzzer, OUTPUT);
  pinMode(botao1, INPUT_PULLUP);
  pinMode(botao2, INPUT_PULLUP);
}
void ligar_led(int valor_convertido){
  i = 0;
  while (valor_convertido > 0 && i < 4) {
    binario[i] = valor_convertido % 2;
    valor_convertido = valor_convertido / 2;
    i++;
  }
  for (int j = i; j >= 0; j--) {
    vetor_binario[j] = binario[j];
  }
  for(int portas = 0; portas <=3; portas++){
    digitalWrite(vetor_leds[portas], vetor_binario[portas + 1]);
  }
  delay(10);
}
void armazena(int valor_convertido_frequencia) {
  vetor_frequencia[f] = valor_convertido_frequencia;
  f++;
}
void leitura_buzzer(){
  int p = 0;
  while (p <= (f - 1)) {
    tone(porta_buzzer, vetor_frequencia[p], 200);
    ligar_led(vetor_frequencia[p] / 200);
    p++;
  }
}
void loop() {
  valor_sensor = analogRead(porta_sensor);
  int valor_convertido = valor_sensor / 273;
  Serial.println(valor_convertido);
  int valor_convertido_frequencia = valor_convertido * 200;
  ligar_led(valor_convertido);
  tone(porta_buzzer, valor_convertido_frequencia , 200);
  if(digitalRead(botao1) == 0){  
    armazena(valor_convertido_frequencia);
  }
  if(digitalRead(botao2) == 0){
    leitura_buzzer();
  }
  delay(10);
}