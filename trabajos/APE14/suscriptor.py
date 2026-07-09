import random

from paho.mqtt import client as mqtt_client
from paho.mqtt.enums import CallbackAPIVersion


BROKER = 'localhost'
PORTO = 1884
TOPICOS = [('laboratorio/temperatura', 0), ('laboratorio/led', 0)]
CLIENT_ID = f'python-mqtt-sub-{random.randint(0, 1000)}'


def al_conectar(client, userdata, flags, rc, properties=None):
    if rc == 0:
        print('¡Conectado exitosamente al Broker MQTT!')
        client.subscribe(TOPICOS)
        print('Suscrito a los topicos: laboratorio/temperatura y laboratorio/led\n')
    else:
        print(f'Error al conectar, codigo de retorno: {rc}')


def al_recibir_mensaje(client, userdata, msg):
    print(f'[Python] Recibido en {msg.topic}: {msg.payload.decode()}')


def run():
    client = mqtt_client.Client(CallbackAPIVersion.VERSION2, CLIENT_ID)
    client.on_connect = al_conectar
    client.on_message = al_recibir_mensaje

    client.connect(BROKER, PORTO)

    try:
        client.loop_forever()
    except KeyboardInterrupt:
        print('\nSuscriptor detenido por el usuario.')


if __name__ == '__main__':
    run()