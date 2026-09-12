const int LED = 2;

bool piscando = false;
unsigned long tempoAnterior = 0;
const unsigned long intervalo = 500;

bool estadoLED = false;

void setup() {
  pinMode(LED, OUTPUT);

  Serial.begin(115200);

  digitalWrite(LED, LOW);
}

void loop() {

  // Verifica se chegou algum comando
  if (Serial.available() > 0) {
    char comando = Serial.read();

    // Ignora quebra de linha
    if (comando == '\n' || comando == '\r') {
      return;
    }

    // Converte para maiúsculo
    comando = toupper(comando);

    if (comando == 'A') {
      piscando = false;
      estadoLED = true;
      digitalWrite(LED, HIGH);

      Serial.println("LED ligado");
    }

    else if (comando == 'B') {
      piscando = true;

      Serial.println("LED piscando...");
    }

    else if (comando == 'C') {
      piscando = false;
      estadoLED = false;
      digitalWrite(LED, LOW);

      Serial.println("LED desligado");
    }
  }

  // Controle da piscada
  if (piscando) {
    unsigned long agora = millis();

    if (agora - tempoAnterior >= intervalo) {
      tempoAnterior = agora;

      estadoLED = !estadoLED;
      digitalWrite(LED, estadoLED);
    }
  }
} 