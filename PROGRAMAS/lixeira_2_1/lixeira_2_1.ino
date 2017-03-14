/*
ALGORITMO - SE O SENSOR PIR DETECTAR ALGUM MOVIMENTO, ABRA A TAMPA.
SE O SENSOR DE DISTANCIA DETECTAR ALGUM LIXO, EMITIR UM SOM E PISCAR OS LEDS


*/

int ledBranco = 4, ledRed = 5, SPir = 12; 
const int trigPin = 8; // DEFINE O PINO DE GATILHO DO SENSOR ULTRASSONICO COMO PORTA 8 
const int echoPin = 7; // DEFINE O PINO RECEPTOR DO SENSOR DE DISTANCIA COMO PORTA 7
#include <Servo.h> // INCLUE UMA BIBLIOTECA DE ARQUIVOS PARA SERVO MECANISMO

Servo myservo; // CRIA UM OBJETO SERVO
void setup(){
myservo.attach(2);  //  CONFIGURA O OBJETO SERVO COMO PORTA 2 
pinMode(trigPin,OUTPUT);  // CONFIGURA O PINO DO SENSOR ULTRASSONIC COMO EMISSOR
pinMode(echoPin,INPUT);   // CONFIGUA O PINO  ||                     COMO RECEPITOR
pinMode(SPir,INPUT);  // CONFIGURA O PINO DO SENSOR PIR COMO UMA ENTRADA DE SINAL
pinMode(ledBranco,OUTPUT); //
pinMode(ledRed,OUTPUT);
Serial.begin(9600);
}


void loop(){

int leitura = digitalRead(SPir);

Serial.println(leitura);

SUtra();


}


void SUtra(){
  
   long duration, inches, cm;

  // The sensor is triggered by a HIGH pulse of 10 or more microseconds.
  // Give a short LOW pulse beforehand to ensure a clean HIGH pulse:
  pinMode(trigPin, OUTPUT);
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  // Read the signal from the sensor: a HIGH pulse whose
  // duration is the time (in microseconds) from the sending
  // of the ping to the reception of its echo off of an object.
  pinMode(echoPin, INPUT);
  duration = pulseIn(echoPin, HIGH);

  // convert the time into a distance
  //inches = microsecondsToInches(duration);
  cm = microsecondsToCentimeters(duration);
  if (cm>30){   
    myservo.write(10); 

 digitalWrite(ledRed,LOW);}
   
  if (cm <= 30 ){
  digitalWrite(ledRed,HIGH);
  myservo.write(170);
  delay(5000);
   
  
  
  }
 
 // else{digitalWrite(ledRed,LOW);myservo.write(90);  }
  //Serial.print(inches);
 // Serial.print("in, ");
  Serial.print(cm);
  Serial.print("cm");
  Serial.println();
  
  delay(25);
}

/*long microsecondsToInches(long microseconds)
{
  // According to Parallax's datasheet for the PING))), there are
  // 73.746 microseconds per inch (i.e. sound travels at 1130 feet per
  // second).  This gives the distance travelled by the ping, outbound
  // and return, so we divide by 2 to get the distance of the obstacle.
  // See: http://www.parallax.com/dl/docs/prod/acc/28015-PING-v1.3.pdf
  return microseconds / 74 / 2;
}*/

long microsecondsToCentimeters(long microseconds)
{
  // The speed of sound is 340 m/s or 29 microseconds per centimeter.
  // The ping travels out and back, so to find the distance of the
  // object we take half of the distance travelled.
  return microseconds / 29 / 2;
  
  }
