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


## Autor

Carlos Josué Granda Cango
