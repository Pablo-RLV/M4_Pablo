int porta_led1 = 1;
int porta_led2 = 2;
int porta_leitor = 4;
int porta_botao = 5;
int porta_buzzer = 7;
void setup() {
  Serial.begin(96000);
  pinMode(porta_led1, OUTPUT);
  pinMode(porta_led2, OUTPUT);
  pinMode(porta_leitor, INPUT);
  pinMode(porta_botao, INPUT);
  pinMode(porta_buzzer, OUTPUT);
}

void loop() {
  int botao = digitalRead(porta_botao);
  if (botao == 1) {
    digitalWrite(porta_led2, 1);
    tone(porta_buzzer, 1000);
    digitalWrite(porta_buzzer, 1);
  } else {
    digitalWrite(porta_led2, 0);
    noTone(porta_buzzer);
    digitalWrite(porta_buzzer, 0);
  }
  digitalWrite(porta_led1, 1);
  int leitura = analogRead(porta_leitor);
  Serial.print(leitura);
}























