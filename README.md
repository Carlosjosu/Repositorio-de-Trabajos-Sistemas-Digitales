# Repositorio de Trabajos - Sistemas Digitales

Este repositorio tendra trabajos, prácticas y ejercicios de la materia de Sistemas Digitales.

## Trabajos cargados

### 1) Práctica de operaciones bitwise con Arduino APE 1

- Fecha: 9 de abril de 2026
- Tema principal: operadores bitwise y control de LED
- Lenguaje: C/C++ (Arduino)

#### Qué hace el programa

1. Inicializa el pin 13 como salida para un LED.
2. Muestra en Monitor Serial ejemplos de operaciones bitwise.
3. Alterna el estado del LED con `XOR`.
4. Lee el estado del bit menos significativo para decidir encendido/apagado.
5. Lleva un contador cíclico y muestra desplazamientos en binario.
6. Registra ciclos y tiempo acumulado por serial.

#### Codigo

Haz clic para abrir el archivo del sketch:

- [Ver codigo Arduino (.ino)](trabajos/2026-04-09-bitwise-arduino.ino)

#### Material necesario

- Arduino UNO (o compatible)
- Cable USB
- LED integrado en pin 13 (o LED externo con resistencia)
- IDE de Arduino

### Circuito armado
<img width="1036" height="527" alt="image" src="https://github.com/user-attachments/assets/a3edc3b6-1f94-4365-aee4-5034bae67fbb" />

### 2) Control de patrones LED con Arduino

- Fecha: 16 de abril de 2026
- Tema principal: Patrones de LEDs, control de eventos y secuencias
- Lenguaje: C/C++ (Arduino)

#### Qué hace el programa

1. Controla 6 LEDs conectados a los pines 2-7.
2. Utiliza un pulsador en el pin 8 para activar/desactivar los patrones.
3. Genera aleatoriamente 5 patrones diferentes cada vez que se presiona el botón:
   - **Patrón 0 (Secuencia)**: LED se desplaza de un lado a otro.
   - **Patrón 1 (Persecución)**: LED con cola de atenuación que se desplaza.
   - **Patrón 2 (Parpadeo)**: Todos los LEDs parpadean sincronizados.
   - **Patrón 3 (Aleatorio)**: LEDs aleatorios con probabilidad de doble destello.
   - **Patrón 4 (Onda)**: Efecto de onda sinusoidal usando PWM.
4. Usa `millis()` para sincronización no bloqueante de tiempos.
5. Implementa lectura de botón con detección de flanco ascendente.

#### Codigo

Haz clic para abrir el archivo del sketch:

- [Ver codigo Arduino (.ino)](trabajos/2026-04-16-patrones-led-arduino.ino)

#### Material necesario

- Arduino UNO (o compatible)
- Cable USB
- 6 LEDs
- 6 resistencias (220Ω - 470Ω)
- 1 Pulsador/Switch
- Protoboard y cables de conexión
- IDE de Arduino

### Circuito armado
<img width="1388" height="931" alt="image" src="https://github.com/user-attachments/assets/399b911d-4df3-480c-9450-0b67a1131d3e" />

### 3) Medición de frecuencia y duty cycle (555 y FF)

- Fecha: 23 de abril de 2026
- Tema principal: medición de frecuencia y ciclo de trabajo en señales digitales
- Lenguaje: C/C++ (Arduino)

#### Qué hace el programa

1. Lee dos señales digitales: una del temporizador 555 y otra de un FF.
2. Detecta flancos de subida y bajada en ambos pines.
3. Calcula el periodo en milisegundos para cada señal.
4. Obtiene la frecuencia en Hz y el duty cycle en porcentaje.
5. Muestra los resultados por Monitor Serial cada 500 ms.

#### Codigo

Haz clic para abrir el archivo del sketch:

- [Ver codigo Arduino (.ino)](trabajos/2026-04-23-medicion-frecuencia-duty-arduino.ino)

#### Material necesario

- Arduino UNO (o compatible)
- Cable USB
- Circuito con temporizador 555
- Flip-Flop (FF)
- Protoboard y cables de conexión
- IDE de Arduino

### Circuito armado
![Circuito armado](Imagenes/Captura%20de%20pantalla%202026-04-22%20223216.png)

### 4) Laboratorio simulado APE 14 con MQTT, Python y ESP32

- Fecha: APE 14
- Tema principal: comunicacion MQTT entre publicador, suscriptor y ESP32
- Lenguaje: Python y C/C++ (Arduino / ESP32)

#### Que hace el laboratorio

1. El script publicador simula una lectura de temperatura y la envia al broker MQTT.
2. El script suscriptor recibe los mensajes de temperatura y el estado del LED.
3. El ESP32 publica la temperatura del sensor LM35 y recibe ordenes para encender o apagar el LED.
4. Se usa FreeRTOS con una tarea para MQTT, una para el sensor y otra para el control del LED.

#### Codigo

Haz clic para abrir los archivos del laboratorio:

- [Ver publicador Python](trabajos/APE14/publicador.py)
- [Ver suscriptor Python](trabajos/APE14/suscriptor.py)
- [Ver codigo ESP32 (.ino)](trabajos/APE14/esp32-ape14.ino)

#### Material necesario

- Broker MQTT ejecutandose en la PC
- Python 3 con la libreria paho-mqtt
- ESP32
- Sensor LM35
- LED y resistencia
- IDE de Arduino o entorno compatible con ESP32

#### Tópicos MQTT usados

- `laboratorio/temperatura`
- `laboratorio/led`


## Autor

Carlos Josué Granda Cango
