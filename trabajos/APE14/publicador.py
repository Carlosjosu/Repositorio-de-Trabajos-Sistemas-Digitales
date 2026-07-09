import random
import time

from paho.mqtt import client as mqtt_client
from paho.mqtt.enums import CallbackAPIVersion


BROKER = 'localhost'
PORTO = 1884
TOPICO_TEMPERATURA = 'laboratorio/temperatura'
CLIENT_ID = f'python-mqtt-pub-{random.randint(0, 1000)}'


def conectar_mqtt():
    client = mqtt_client.Client(CallbackAPIVersion.VERSION2, CLIENT_ID)
    client.connect(BROKER, PORTO)
    return client


def publicar(client):
    while True:
        time.sleep(2)
        temperatura = round(random.uniform(20.0, 30.0), 1)
        payload = str(temperatura)

        resultado = client.publish(TOPICO_TEMPERATURA, payload)

        if resultado.rc == 0:
            print(f'[Python] Enviado: {temperatura} al topico {TOPICO_TEMPERATURA}')
        else:
            print(f'Fallo al enviar el mensaje al topico {TOPICO_TEMPERATURA}')


def run():
    client = conectar_mqtt()
    client.loop_start()

    try:
        publicar(client)
    except KeyboardInterrupt:
        print('\nPublicador detenido por el usuario.')
        client.loop_stop()


if __name__ == '__main__':
    run()