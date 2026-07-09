#include <WiFi.h>
#include <PubSubClient.h>

const char* ssid = "Internet_UNL";
const char* password = "UNL1859WiFi";
const char* mqtt_server = "10.20.xxx.xx";
const int mqtt_port = 1884;

const int ledPin = 4;
const int sensorPin = 34;

WiFiClient espClient;
PubSubClient client(espClient);

SemaphoreHandle_t xLedSemaphore;
volatile bool ledState = false;

void setup_wifi() {
  Serial.print("Conectando a ");
  Serial.println(ssid);
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    vTaskDelay(500 / portTICK_PERIOD_MS);
    Serial.print(".");
  }
  Serial.println("\nWiFi conectado. IP: ");
  Serial.println(WiFi.localIP());
}

void callback(char* topic, byte* payload, unsigned int length) {
  String mensaje = "";
  for (unsigned int i = 0; i < length; i++) {
    mensaje += (char)payload[i];
  }

  if (String(topic) == "laboratorio/led") {
    if (mensaje == "ON") {
      ledState = true;
    } else if (mensaje == "OFF") {
      ledState = false;
    }
    xSemaphoreGive(xLedSemaphore);
  }
}

void vTaskMQTT(void *pvParameters) {
  while (true) {
    if (!client.connected()) {
      Serial.print("Intentando conexion MQTT...");
      String clientId = "ESP32Client-" + String(random(0xffff), HEX);
      if (client.connect(clientId.c_str())) {
        Serial.println("¡Conectado al Broker!");
        client.subscribe("laboratorio/led");
      } else {
        vTaskDelay(5000 / portTICK_PERIOD_MS);
      }
    }

    client.loop();
    vTaskDelay(10 / portTICK_PERIOD_MS);
  }
}

void vTaskSensor(void *pvParameters) {
  while (true) {
    int lecturaAnaloga = analogRead(sensorPin);
    float temperatura = (lecturaAnaloga / 4095.0) * 330.0;

    char tempString[8];
    dtostrf(temperatura, 1, 2, tempString);

    if (client.connected()) {
      client.publish("laboratorio/temperatura", tempString);
      Serial.print("[SENSOR] Temperatura publicada: ");
      Serial.println(tempString);
    }

    vTaskDelay(2000 / portTICK_PERIOD_MS);
  }
}

void vTaskLED(void *pvParameters) {
  while (true) {
    if (xSemaphoreTake(xLedSemaphore, portMAX_DELAY) == pdTRUE) {
      digitalWrite(ledPin, ledState ? HIGH : LOW);
      Serial.println("[MQTT] Estado del LED actualizado via Semaforo.");
    }
  }
}

void setup() {
  Serial.begin(115200);
  pinMode(ledPin, OUTPUT);

  setup_wifi();
  client.setServer(mqtt_server, mqtt_port);
  client.setCallback(callback);

  xLedSemaphore = xSemaphoreCreateBinary();

  xTaskCreatePinnedToCore(vTaskMQTT, "TareaMQTT", 4096, NULL, 1, NULL, 1);
  xTaskCreatePinnedToCore(vTaskSensor, "TareaSensor", 2048, NULL, 1, NULL, 1);
  xTaskCreatePinnedToCore(vTaskLED, "TareaLED", 1024, NULL, 1, NULL, 1);
}

void loop() {
  vTaskDelete(NULL);
}