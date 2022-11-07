int led1 = 4;
int led2 = 5;
int led3 = 6;
int led4 = 7;
int porta_sensor = 8;
int porta_buzzer = 3;
int vetor[4] = {led1, led2, led3, led4};
int valor_sensor = 0;
int binario[4]={0,0,0,0};
int vetor_binario[4] = {0, 0, 0, 0};
int i = 0;
void setup() {
  Serial.begin(115200);
  for(int portas=0; portas <= 3; portas++){
    pinMode(vetor[portas], OUTPUT);
  }
  pinMode(porta_sensor, INPUT);
}
void loop() {
  valor_sensor = analogRead(porta_sensor);
  int valor_convertido = valor_sensor / 537;
  tone(porta_buzzer, 50 * valor_convertido);

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
    digitalWrite(vetor[portas], vetor_binario[portas + 1]);
  }
  delay(100);
}









