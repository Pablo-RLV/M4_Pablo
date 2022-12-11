#include <WiFi.h>

const char *ssid = "SHARE-RESIDENTE";
const char *password = "Share@residente";
// const char* ssid = "Inteli-COLLEGE"; // set the wi-fi name
// const char* password = "QazWsx@123";  // set the wi-fi password

WiFiServer server(80);

void setup()
{
    pinMode(1, OUTPUT); // set the buzzer pin mode
    pinMode(2, OUTPUT); // set the buzzer pin mode
    Serial.begin(115200); // start the terminal
    delay(10);
    // We start by connecting to a WiFi network
    Serial.println();
    Serial.println();
    Serial.print("Connecting to ");
    Serial.println(ssid);
    WiFi.begin(ssid, password);
    while (WiFi.status() != WL_CONNECTED) {
        delay(500);
        Serial.print(".");
    }
    Serial.println("");
    Serial.println("WiFi connected."); // show that the WiFi was sucessfully connected 
    Serial.println("IP address: ");
    Serial.println(WiFi.localIP()); // print the ip adress that will be used to connect to the server 
    server.begin();
}

void loop(){
 WiFiClient client = server.available();   // listen for incoming clients
  if (client) {                             // if you get a client,
    Serial.println("New Client.");           // print a message out the serial port
    String currentLine = "";                // make a String to hold incoming data from the client
    while (client.connected()) {            // loop while the client's connected
      if (client.available()) {             // if there's bytes to read from the client,
        char c = client.read();             // read a byte, then
        Serial.write(c);                    // print it out the serial monitor
        if (c == '\n') {                    // if the byte is a newline character
          // if the current line is blank, you got two newline characters in a row.
          // that's the end of the client HTTP request, so send a response:
          if (currentLine.length() == 0) {
            // HTTP headers always start with a response code (e.g. HTTP/1.1 200 OK)
            // and a content-type so the client knows what's coming, then a blank line:
            client.println("HTTP/1.1 200 OK");
            client.println("Content-type:text/html");
            client.println();
            // the content of the HTTP response follows the header:
            client.println("<!DOCTYPE html><html lang='en'><head> <meta charset='UTF-8'> <meta http-equiv='X-UA-Compatible' content='IE=edge'> <meta name='viewport' content='width=device-width, initial-scale=1.0'> <link rel='stylesheet' href='https://cdn.jsdelivr.net/npm/bootstrap@4.3.1/dist/css/bootstrap.min.css' integrity='sha384-ggOyR0iXCbMQv3Xipma34MD+dH/1fQ784/j6cY/iJTQUOhcWr7x9JvoRxT2MZw1T' crossorigin='anonymous'> <title>Document</title> <style> .body{ background-color: #e0e0e0; } .titulo{ color: green } .subtitle{ text-align: center; } .cor1{ color: blue; } .cor2{ color: red; } .metade1{ width:50%; float:left; } .metade2{ width:50%; float:right; } .imagens{ text-align: center; line-height: 0%; } .icons{ height: 20px; width: 50px; border: 1px solid black; } </style></head><body class='body'> <center> <h1 class='titulo'>Quem clica mais rápido?</h1> <div> <!-- <a href='/'> --> <input type='button' id='reiniciar' class='btn btn-success' value='Reiniciar' onclick='reiniciar()'> <!-- </a> --> </div> <div class='metade1'> <h2 class='subtitle cor1'>Jogador 1</h2> <div class='imagens'> <img class='icons' id='1-1' src='https://i0.wp.com/www.multarte.com.br/wp-content/uploads/2018/12/fundo-branco-liso2-1024x1024.jpg?resize=696%2C696&ssl=1'> <br> <img class='icons' id='1-2' src='https://i0.wp.com/www.multarte.com.br/wp-content/uploads/2018/12/fundo-branco-liso2-1024x1024.jpg?resize=696%2C696&ssl=1'> <br> <img class='icons' id='1-3' src='https://i0.wp.com/www.multarte.com.br/wp-content/uploads/2018/12/fundo-branco-liso2-1024x1024.jpg?resize=696%2C696&ssl=1'> <br> <img class='icons' id='1-4' src='https://i0.wp.com/www.multarte.com.br/wp-content/uploads/2018/12/fundo-branco-liso2-1024x1024.jpg?resize=696%2C696&ssl=1'> <br> <img class='icons' id='1-5' src='https://i0.wp.com/www.multarte.com.br/wp-content/uploads/2018/12/fundo-branco-liso2-1024x1024.jpg?resize=696%2C696&ssl=1'> <br> <img class='icons' id='1-6' src='https://i0.wp.com/www.multarte.com.br/wp-content/uploads/2018/12/fundo-branco-liso2-1024x1024.jpg?resize=696%2C696&ssl=1'> <br> <img class='icons' id='1-7' src='https://i0.wp.com/www.multarte.com.br/wp-content/uploads/2018/12/fundo-branco-liso2-1024x1024.jpg?resize=696%2C696&ssl=1'> <br> <img class='icons' id='1-8' src='https://i0.wp.com/www.multarte.com.br/wp-content/uploads/2018/12/fundo-branco-liso2-1024x1024.jpg?resize=696%2C696&ssl=1'> <br> <img class='icons' id='1-9' src='https://i0.wp.com/www.multarte.com.br/wp-content/uploads/2018/12/fundo-branco-liso2-1024x1024.jpg?resize=696%2C696&ssl=1'> <br> <img class='icons' id='1-10' src='https://i0.wp.com/www.multarte.com.br/wp-content/uploads/2018/12/fundo-branco-liso2-1024x1024.jpg?resize=696%2C696&ssl=1'> <br> </div> <br> <!-- <a href='/'> --> <input type='button' id='botao1' class='btn btn-primary' value='Pressione' onclick='jogador1()'> <!-- </a> --> </div> <div class='metade2'> <h2 class='subtitle cor2'>Jogador 2</h2> <div class='imagens'> <img class='icons' id='2-1' src='https://i0.wp.com/www.multarte.com.br/wp-content/uploads/2018/12/fundo-branco-liso2-1024x1024.jpg?resize=696%2C696&ssl=1'> <br> <img class='icons' id='2-2' src='https://i0.wp.com/www.multarte.com.br/wp-content/uploads/2018/12/fundo-branco-liso2-1024x1024.jpg?resize=696%2C696&ssl=1'> <br> <img class='icons' id='2-3' src='https://i0.wp.com/www.multarte.com.br/wp-content/uploads/2018/12/fundo-branco-liso2-1024x1024.jpg?resize=696%2C696&ssl=1'> <br> <img class='icons' id='2-4' src='https://i0.wp.com/www.multarte.com.br/wp-content/uploads/2018/12/fundo-branco-liso2-1024x1024.jpg?resize=696%2C696&ssl=1'> <br> <img class='icons' id='2-5' src='https://i0.wp.com/www.multarte.com.br/wp-content/uploads/2018/12/fundo-branco-liso2-1024x1024.jpg?resize=696%2C696&ssl=1'> <br> <img class='icons' id='2-6' src='https://i0.wp.com/www.multarte.com.br/wp-content/uploads/2018/12/fundo-branco-liso2-1024x1024.jpg?resize=696%2C696&ssl=1'> <br> <img class='icons' id='2-7' src='https://i0.wp.com/www.multarte.com.br/wp-content/uploads/2018/12/fundo-branco-liso2-1024x1024.jpg?resize=696%2C696&ssl=1'> <br> <img class='icons' id='2-8' src='https://i0.wp.com/www.multarte.com.br/wp-content/uploads/2018/12/fundo-branco-liso2-1024x1024.jpg?resize=696%2C696&ssl=1'> <br> <img class='icons' id='2-9' src='https://i0.wp.com/www.multarte.com.br/wp-content/uploads/2018/12/fundo-branco-liso2-1024x1024.jpg?resize=696%2C696&ssl=1'> <br> <img class='icons' id='2-10' src='https://i0.wp.com/www.multarte.com.br/wp-content/uploads/2018/12/fundo-branco-liso2-1024x1024.jpg?resize=696%2C696&ssl=1'> <br> </div> <br> <!-- <a href='/'> --> <input type='button' id='botao2' class='btn btn-danger' value='Pressione' onclick='jogador2()'> <!-- </a> --> </div> </center></body><script src='https://ajax.googleapis.com/ajax/libs/jquery/2.1.3/jquery.min.js'></script><script> var contador1 = 0; var contador2 = 0; var finalizou = 0; const link = window.location.href; function jogador1(){ if(contador1 < 10 && contador2 < 10){ contador1++; $('#1-' + String(11 - contador1)).prop('src', 'https://png.pngtree.com/thumb_back/fw800/background/20210207/pngtree-blue-pure-color-simple-background-image_557085.jpg'); } else{ if(finalizou == 0){ alert('O jogador 1 venceu!'); } direcionar_url('J1'); finalizou = 1; encerrar(); } } function jogador2(){ if(contador2 < 10 && contador1 < 10){ contador2++; $('#2-' + String(11 - contador2)).prop('src', 'https://png.pngtree.com/thumb_back/fw800/background/20210207/pngtree-red-background-simple-solid-color-image_556955.jpg'); } else{ if(finalizou == 0){ alert('O jogador 2 venceu!'); } direcionar_url('J2'); finalizou = 1; encerrar(); } } function encerrar(){ $('#botao2').addClass('disabled'); $('#botao1').addClass('disabled'); } function reiniciar(){ contador1 = 0; contador2 = 0; finalizou = 0; $('#botao2').removeClass('disabled'); $('#botao1').removeClass('disabled'); for(i=1; i<=10; i++){ $('#1-' + String(i)).prop('src', 'https://i0.wp.com/www.multarte.com.br/wp-content/uploads/2018/12/fundo-branco-liso2-1024x1024.jpg?resize=696%2C696&ssl=1'); $('#2-' + String(i)).prop('src', 'https://i0.wp.com/www.multarte.com.br/wp-content/uploads/2018/12/fundo-branco-liso2-1024x1024.jpg?resize=696%2C696&ssl=1'); } } function direcionar_url(ganhador){window.location = 'http://10.254.18.75/' + ganhador; }</script></html>");
            // The HTTP response ends with another blank line:
            client.println();
            // break out of the while loop:
            break;
          } else {    // if you got a newline, then clear currentLine:
            currentLine = "";
          }
        } else if (c != '\r') {  // if you got anything else but a carriage return character,
          currentLine += c;      // add it to the end of the currentLine
        }
        Serial.println(currentLine);
        if (currentLine.endsWith("GET /J1")) {
          digitalWrite(1, 1);               // GET /H turns the LED on
          digitalWrite(2, 0);               // GET /H turns the LED on
        }
        if (currentLine.endsWith("GET /J2")) {
          digitalWrite(1, 0);                // GET /L turns the LED off
          digitalWrite(2, 1);                // GET /L turns the LED off
        }
      }
    }
    // close the connection:
    client.stop();
    Serial.println("Client Disconnected.");
  }
}