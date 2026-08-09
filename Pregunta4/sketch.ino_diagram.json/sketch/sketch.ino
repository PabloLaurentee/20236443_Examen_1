
//  EXAMEN PARCIAL - PREGUNTA 4
//  Control de un LED RGB con pulsadores y potenciometro
//  Pablo Andres Laurente Salazar - 20236443


// DEFINICION DE PINES
#define SW1   18    // Pulsador 1 conectado al GPIO18
#define SW2   17    // Pulsador 2 conectado al GPIO17
#define POT   34    // Potenciometro conectado al GPIO34
#define LED_B 25    // Canal AZUL del LED 
#define LED_G 26    // Canal VERDE del LED 
#define LED_R 27    // Canal ROJO del LED

//  VARIABLES GLOBALES 
int valorPot = 0;   // Valor leido del ADC (0 a 4095)
int tiempo   = 0;   // Tiempo de retardo escalado (1000 a 4000 ms) 


// Apaga los tres canales del LED 
void apagarLED() {
  digitalWrite(LED_R, LOW);
  digitalWrite(LED_G, LOW);
  digitalWrite(LED_B, LOW);
}

// Hace parpadear 3 veces el color indicado
// pin -> canal de color a encender
// t -> tiempo de encendido y apagado en milisegundos
void parpadear(int pin, int t) {
  for (int i = 0; i < 3; i++) {
    digitalWrite(pin, HIGH);  // Enciende el color
    delay(tiempo);            // Permanece encendido
    digitalWrite(pin, LOW);   // Apaga el color
    delay(tiempo);            // Permanece apagado el mismo intervalo
  }
}

// Imprime en el Monitor Serial la informacion solicitada
void mostrarDatos(String boton) {
  Serial.print("Boton presionado: ");
  Serial.println(boton);
  Serial.print("Valor del potenciometro: ");
  Serial.println(valorPot);
  Serial.print("Tiempo de retardo: ");
  Serial.print(tiempo);
  Serial.println(" ms");
  Serial.println("-------------------------");
}


void setup() {
  Serial.begin(115200);

  // Botones con resistencia pull-up interna:
  // en reposo leen HIGH y al presionarse leen LOW
  pinMode(SW1, INPUT_PULLUP);
  pinMode(SW2, INPUT_PULLUP);

  // Canales del LED como salidas digitales
  pinMode(LED_R, OUTPUT);
  pinMode(LED_G, OUTPUT);
  pinMode(LED_B, OUTPUT);

  apagarLED();   // El LED inicia apagado
}


void loop() {

  //  SW1: Rojo -> Verde -> Azul 
  if (digitalRead(SW1) == LOW) {
    valorPot = analogRead(POT);                    // Lee el potenciometro
    tiempo = map(valorPot, 0, 4095, 1000, 4000);   // Escala a milisegundos
    mostrarDatos("SW1");

    // El color designado parpadea 3 veces 

    parpadear(LED_R, tiempo);
    parpadear(LED_G, tiempo);
    parpadear(LED_B, tiempo);

    apagarLED(); // Se apaga una vez acaba
  }

  // SW2: Azul -> Verde -> Rojo 
  if (digitalRead(SW2) == LOW) {
    valorPot = analogRead(POT);                   // Lo mismo que el SW1
    tiempo = map(valorPot, 0, 4095, 1000, 4000);
    mostrarDatos("SW2");

    // El color designado parpadea 3 veces 

    parpadear(LED_B, tiempo);
    parpadear(LED_G, tiempo);
    parpadear(LED_R, tiempo);

    apagarLED();
  }
}