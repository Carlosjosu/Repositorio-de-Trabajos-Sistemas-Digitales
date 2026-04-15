const uint8_t ledPins[] = {2, 3, 4, 5, 6, 7};
const uint8_t numLeds = sizeof(ledPins) / sizeof(ledPins[0]);
const uint8_t switchPin = 8;

int patronActual = 0;
bool switchEncendido = false;
bool estadoAnteriorSwitch = false;

unsigned long lastMillis = 0;
const unsigned long baseDelay = 150; 

void setup() {
  for (uint8_t i = 0; i < numLeds; i++) {
    pinMode(ledPins[i], OUTPUT);
    digitalWrite(ledPins[i], LOW);
  }
  
  pinMode(switchPin, INPUT_PULLUP); 
  
  randomSeed(analogRead(A0));
}

void loop() {
  switchEncendido = (digitalRead(switchPin) == LOW);

  if (switchEncendido == true && estadoAnteriorSwitch == false) {
    patronActual = random(0, 5); 
    apagarTodos();               
  }

  if (switchEncendido) {
    switch (patronActual) {
      case 0: patronSecuencia(); break;
      case 1: patronPersecucion(); break;
      case 2: patronParpadeo(); break;
      case 3: patronAleatorio(); break;
      case 4: patronOnda(); break;
    }
  } else {
    apagarTodos();
  }

  
  estadoAnteriorSwitch = switchEncendido;
}

void patronSecuencia() {
  static int idx = 0;
  static int dir = 1;
  if (millis() - lastMillis >= baseDelay) {
    apagarTodos();
    digitalWrite(ledPins[idx], HIGH);
    idx += dir;
    if (idx >= numLeds) { idx = numLeds - 2; dir = -1; }
    if (idx < 0) { idx = 1; dir = 1; }
    lastMillis = millis();
  }
}

void patronPersecucion() {
  static int head = 0;
  const int trail = 2;
  if (millis() - lastMillis >= baseDelay / 1.5) {
    apagarTodos();
    for (int t = 0; t <= trail; t++) {
      int p = (head - t + numLeds) % numLeds;
      analogWrite(ledPins[p], 255 / (t + 1));
    }
    head = (head + 1) % numLeds;
    lastMillis = millis();
  }
}

void patronParpadeo() {
  static bool on = false;
  if (millis() - lastMillis >= baseDelay * 3) {
    on = !on;
    for (uint8_t i = 0; i < numLeds; i++) digitalWrite(ledPins[i], on ? HIGH : LOW);
    lastMillis = millis();
  }
}

void patronAleatorio() {
  if (millis() - lastMillis >= baseDelay) {
    apagarTodos();
    int r = random(numLeds);
    digitalWrite(ledPins[r], HIGH);
    
    if (random(100) < 40) {
      int r2 = random(numLeds);
      digitalWrite(ledPins[r2], HIGH);
    }
    lastMillis = millis();
  }
}

void patronOnda() {
  static int step = 0;
  const int stepsPerCycle = 24;
  if (millis() - lastMillis >= baseDelay / 2) {
    for (uint8_t i = 0; i < numLeds; i++) {
      float phase = (float)(step + i * (stepsPerCycle / numLeds)) * (2.0 * PI / stepsPerCycle);
      int val = (int)((sin(phase) + 1.0) * 127.5);
      analogWrite(ledPins[i], val);
    }
    step = (step + 1) % stepsPerCycle;
    lastMillis = millis();
  }
}

void apagarTodos() {
  for (uint8_t i = 0; i < numLeds; i++) {
    digitalWrite(ledPins[i], LOW);
  }
}
