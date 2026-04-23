const int pin555 = 2;
const int pinFF = 3;

bool estadoActual555 = LOW;
bool estadoAnterior555 = LOW;
unsigned long tAnteriorFlanco555 = 0;
unsigned long tCambio555 = 0;
float tHigh555 = 0, tLow555 = 0;
float periodo555 = 0, freq555 = 0, duty555 = 0;

bool estadoActualFF = LOW;
bool estadoAnteriorFF = LOW;
unsigned long tAnteriorFlancoFF = 0;
unsigned long tCambioFF = 0;
float tHighFF = 0, tLowFF = 0;
float periodoFF = 0, freqFF = 0, dutyFF = 0;

unsigned long tUltimaImpresion = 0;

void setup() {
  Serial.begin(115200);
  pinMode(pin555, INPUT);
  pinMode(pinFF, INPUT);
}

void loop() {
  unsigned long tiempoActual = millis();

  estadoActual555 = digitalRead(pin555);

  if (estadoActual555 != estadoAnterior555) {
    if (estadoActual555 == HIGH) {
      periodo555 = tiempoActual - tAnteriorFlanco555;
      tAnteriorFlanco555 = tiempoActual;

      if (periodo555 > 0) {
        freq555 = 1000.0 / periodo555;
      }

      tLow555 = tiempoActual - tCambio555;
    } else {
      tHigh555 = tiempoActual - tCambio555;
    }

    if ((tHigh555 + tLow555) > 0) {
      duty555 = (tHigh555 / (tHigh555 + tLow555)) * 100.0;
    }

    tCambio555 = tiempoActual;
    estadoAnterior555 = estadoActual555;
  }

  estadoActualFF = digitalRead(pinFF);

  if (estadoActualFF != estadoAnteriorFF) {
    if (estadoActualFF == HIGH) {
      periodoFF = tiempoActual - tAnteriorFlancoFF;
      tAnteriorFlancoFF = tiempoActual;

      if (periodoFF > 0) {
        freqFF = 1000.0 / periodoFF;
      }
      tLowFF = tiempoActual - tCambioFF;
    } else {
      tHighFF = tiempoActual - tCambioFF;
    }

    if ((tHighFF + tLowFF) > 0) {
      dutyFF = (tHighFF / (tHighFF + tLowFF)) * 100.0;
    }

    tCambioFF = tiempoActual;
    estadoAnteriorFF = estadoActualFF;
  }

  if (tiempoActual - tUltimaImpresion >= 500) {
    tUltimaImpresion = tiempoActual;

    Serial.print("555 -> Freq: "); Serial.print(freq555); Serial.print(" Hz | Duty: "); Serial.print(duty555); Serial.println("%");
    Serial.print("FF  -> Freq: "); Serial.print(freqFF); Serial.print(" Hz | Duty: "); Serial.print(dutyFF); Serial.println("%");
    Serial.println("--------------------------------------------------");
  }
}
