# Proyecto-Arduino_Sistema-de-Barrera-por-Proximidad
En este proyecto explicaremos como implementar un sistema de barrera que funcione por proximidad, como si fuera un semáforo

# Materiales necesarios
- Arduino UNO
- 3 LEDS (Rojo, Amarillo, Verde)
- Servo 180º
- Sensor Ultrasonidos

# Explicación
Lo primero de todo será inicializar una variable, que llamaremos "Distancia", a un valor aleatorio, en este caso será 789.

Dentro del bucle, establecemos que la variable creada anteriormente se iguale a lo que mida el sensor ultrasonidos en centímetros. Este sensor tendrá el Pin del "trigger" conectado al Pin nº 5 de Arduino UNO y el de "echo", al Pin nº 3 de Arduino UNO.

Una vez echo esto, verificamos la distancia que mide el sensor ultrasonidos y movemos el servo a un cierto angulo y se encenderá algún led. Hay que señalar que el servo se conectará al Pin nº 9 de Arduino UNO y los leds, entre los Pines 11 y 13 de Arduino UNO.
Por ejemplo, en el caso de que lo que mida el sensor sea entre 252 y 20 cm, el servo estará en un ángulo de 0 grados con el led rojo encendido y el resto de leds apagados.
Otro caso será si la distancia es menor a 6 cm, lo cual hará que el servo se situe en un ángulo de 90 grados con el led verde encendido y el resto de leds apagados.

Tras hacer estas verificaciones mostramos la distancia actual que existe entre el objeto más cercano al sensor y este.
Por último esperamos 1 segundo (o 1000 milisegundos) antes de volver a empezar.


# Resultado final en TinkerCAD
Una vez realizado esto, si creamos un proyecto en TinkerCAD, el circuito resultante para que este código funcione es el siguiente:
![image](https://github.com/user-attachments/assets/80712c22-ce69-44a0-bedc-5fc8bba14a63)
