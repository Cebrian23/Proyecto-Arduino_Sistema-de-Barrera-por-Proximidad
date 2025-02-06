#include <Servo.h>

double Distancia;
Servo servo_9;

double fnc_ultrasonic_distance(int _t, int _e){
	unsigned long dur=0;
	digitalWrite(_t, LOW);
	delayMicroseconds(5);
	digitalWrite(_t, HIGH);
	delayMicroseconds(10);
	digitalWrite(_t, LOW);
	dur = pulseIn(_e, HIGH, 18000);
	if(dur==0)return 999.0;
	return (dur/57);
}

void Abierto() {
	digitalWrite(13,HIGH);
	digitalWrite(12,LOW);
	digitalWrite(11,LOW);
}
void A_medias() {
	digitalWrite(13,LOW);
	digitalWrite(12,HIGH);
	digitalWrite(11,LOW);
}
void Cerrado() {
	digitalWrite(13,LOW);
	digitalWrite(12,LOW);
	digitalWrite(11,HIGH);
}
void Fuera_rango() {
	digitalWrite(13,LOW);
	digitalWrite(12,LOW);
	digitalWrite(11,LOW);
}

void setup()
{
  	pinMode(3, OUTPUT);
	pinMode(4, INPUT);
	servo_9.attach(9);
	pinMode(13, OUTPUT);
	pinMode(12, OUTPUT);
	pinMode(11, OUTPUT);

	Serial.begin(9600);
	Serial.flush();
	while(Serial.available()>0)Serial.read();

	Distancia = 789;

}


void loop()
{

  	Distancia = fnc_ultrasonic_distance(3,4);
  	if (((Distancia <= 252) && (Distancia >= 20))) {
  		servo_9.write(0);
  		Cerrado();
  	}
  	else if (((Distancia <= 20) && (Distancia >= 6))) {
  		servo_9.write(45);
  		A_medias();
  	}
  	else if ((Distancia <= 6)) {
  		servo_9.write(90);
  		Abierto();
  	}
  	else if ((Distancia >= 999)) {
  		servo_9.write(0);
  		Fuera_rango();
  	}

  	Serial.print(String("La distancia ahora es "));
  	Serial.print(Distancia);
  	Serial.println(String(" cm"));
  	delay(1000);

}