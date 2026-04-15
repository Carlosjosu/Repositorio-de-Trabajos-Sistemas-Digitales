
// Declaracion de variables de diferentes tipos
const int LED_PIN = 13;       // Tipo int
byte estadoLed = 0;           // Tipo byte
int contador = 0;             // Tipo int

long ciclosTotales = 0;       // Tipo long
float tiempoSegundos = 0.0;   // Tipo float
bool ledEncendido = false;    // Tipo bool

void setup() {
  pinMode(LED_PIN, OUTPUT);
  Serial.begin(9600);

  Serial.println("--- Ejemplos de Operaciones Bitwise ---");
  Serial.print("AND (5 & 3): "); Serial.println(5 & 3);
  Serial.print("OR  (5 | 3): "); Serial.println(5 | 3);
  Serial.print("XOR (5 ^ 3): "); Serial.println(5 ^ 3);
  Serial.print("NOT (~5)   : "); Serial.println(~5);
  Serial.print("Shift (1<<2): "); Serial.println(1 << 2);
  Serial.println("---------------------------------------");

  // Inicializacion Bitwise OR
  estadoLed = estadoLed | (1 << 0);
}

void loop() {
  estadoLed = estadoLed ^ 0b00000001;

  ledEncendido = ((estadoLed & 1) == 1);

  if (ledEncendido) {
    digitalWrite(LED_PIN, HIGH);
  } else {
    digitalWrite(LED_PIN, LOW);
  }

  // Esperar 500 ms
  delay(500);

  // Operaciones matematicas
  contador = (contador + 1) % 8;
  ciclosTotales = ciclosTotales + 1;
  tiempoSegundos = ciclosTotales * 1.0;

  Serial.print("Shift BIN: ");
  Serial.print(1 << contador, BIN);

  Serial.print(" | Ciclo: "); Serial.print(ciclosTotales);
  Serial.print(" | Tiempo: "); Serial.print(tiempoSegundos);
  Serial.println("s");

  // Esperar 500 ms
  delay(500);
}
