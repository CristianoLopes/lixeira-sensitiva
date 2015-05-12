# lixeira-sensitiva
Desenvolvimento de dispositivos sensitivos
/*
 * PIR sensor tester
 */

/*
  Play melody
*/

/*************************************************
 * Public Constants
 *************************************************/

#define NOTE_  00
#define NOTE_B0  31
#define NOTE_C1  33
#define NOTE_CS1 35
#define NOTE_D1  37
#define NOTE_DS1 39
#define NOTE_E1  41
#define NOTE_F1  44
#define NOTE_FS1 46
#define NOTE_G1  49
#define NOTE_GS1 52
#define NOTE_A1  55
#define NOTE_AS1 58
#define NOTE_B1  62
#define NOTE_C2  65
#define NOTE_CS2 69
#define NOTE_D2  73
#define NOTE_DS2 78
#define NOTE_E2  82
#define NOTE_F2  87
#define NOTE_FS2 93
#define NOTE_G2  98
#define NOTE_GS2 104
#define NOTE_A2  110
#define NOTE_AS2 117
#define NOTE_B2  123
#define NOTE_C3  131
#define NOTE_CS3 139
#define NOTE_D3  147
#define NOTE_DS3 156
#define NOTE_E3  165
#define NOTE_F3  175
#define NOTE_FS3 185
#define NOTE_G3  196
#define NOTE_GS3 208
#define NOTE_A3  220
#define NOTE_AS3 233
#define NOTE_B3  247
#define NOTE_C4  262
#define NOTE_CS4 277
#define NOTE_D4  294
#define NOTE_DS4 311
#define NOTE_E4  330
#define NOTE_F4  349
#define NOTE_FS4 370
#define NOTE_G4  392
#define NOTE_GS4 415
#define NOTE_A4  440
#define NOTE_AS4 466
#define NOTE_B4  494
#define NOTE_C5  523
#define NOTE_CS5 554
#define NOTE_D5  587
#define NOTE_DS5 622
#define NOTE_E5  659
#define NOTE_F5  698
#define NOTE_FS5 740
#define NOTE_G5  784
#define NOTE_GS5 831
#define NOTE_A5  880
#define NOTE_AS5 932
#define NOTE_B5  988
#define NOTE_C6  1047
#define NOTE_CS6 1109
#define NOTE_D6  1175
#define NOTE_DS6 1245
#define NOTE_E6  1319
#define NOTE_F6  1397
#define NOTE_FS6 1480
#define NOTE_G6  1568
#define NOTE_GS6 1661
#define NOTE_A6  1760
#define NOTE_AS6 1865
#define NOTE_B6  1976
#define NOTE_C7  2093
#define NOTE_CS7 2217
#define NOTE_D7  2349
#define NOTE_DS7 2489
#define NOTE_E7  2637
#define NOTE_F7  2794
#define NOTE_FS7 2960
#define NOTE_G7  3136
#define NOTE_GS7 3322
#define NOTE_A7  3520
#define NOTE_AS7 3729
#define NOTE_B7  3951
#define NOTE_C8  4186
#define NOTE_CS8 4435
#define NOTE_D8  4699
#define NOTE_DS8 4978

#include <TrueRandom.h>
#include <Servo.h> // inclue comandos do servomecanismo
Servo servo1; // cria um objeto servo de nome servo1

//vassourinhas
int notes[] = {NOTE_,NOTE_,NOTE_E5,NOTE_,NOTE_A5,NOTE_,NOTE_A5,NOTE_,NOTE_G5,NOTE_FS5,NOTE_,NOTE_,NOTE_B5,NOTE_,NOTE_F5,NOTE_E5,NOTE_F5,NOTE_E5,NOTE_F5,NOTE_G5,NOTE_F5,NOTE_,NOTE_,NOTE_E5,NOTE_D5,NOTE_E5,NOTE_D5,NOTE_E5,NOTE_F5,NOTE_E5,NOTE_,NOTE_,NOTE_F5,NOTE_E5,NOTE_F5,NOTE_E5,NOTE_F5,NOTE_G5,NOTE_F5,NOTE_E5,NOTE_D5,NOTE_C5,NOTE_B4,NOTE_A5,NOTE_G5,NOTE_F5,NOTE_E5,NOTE_E5,NOTE_,NOTE_,NOTE_E5,NOTE_,NOTE_,NOTE_,NOTE_,NOTE_F5,NOTE_E5,NOTE_F5,NOTE_E5,NOTE_F5,NOTE_G5,NOTE_F5,NOTE_,NOTE_,NOTE_E5,NOTE_D5,NOTE_E5,NOTE_D5,NOTE_E5,NOTE_F5,NOTE_E5,NOTE_,NOTE_,NOTE_F5,NOTE_E5,NOTE_F5,NOTE_E5,NOTE_F5,NOTE_G5,NOTE_F5,NOTE_E5,NOTE_D5,NOTE_C5,NOTE_B4,NOTE_A5,NOTE_G5,NOTE_F5,NOTE_E5,NOTE_E5,NOTE_,NOTE_,NOTE_E5,NOTE_,NOTE_,NOTE_,NOTE_,NOTE_G5,NOTE_,NOTE_F5,NOTE_,NOTE_,};
int durations[] = {1000.0000000000001,250.00000000000003,250.00000000000003,250.00000000000003,250.00000000000003,250.00000000000003,250.00000000000003,250.00000000000003,1000.0000000000001,500.00000000000006,250.00000000000003,250.00000000000003,250.00000000000003,500.00000000000006,250.00000000000003,250.00000000000003,250.00000000000003,250.00000000000003,250.00000000000003,250.00000000000003,1500.0,500.00000000000006,500.00000000000006,250.00000000000003,250.00000000000003,250.00000000000003,250.00000000000003,250.00000000000003,250.00000000000003,1500.0,500.00000000000006,500.00000000000006,250.00000000000003,250.00000000000003,250.00000000000003,250.00000000000003,250.00000000000003,250.00000000000003,250.00000000000003,250.00000000000003,250.00000000000003,250.00000000000003,250.00000000000003,250.00000000000003,250.00000000000003,250.00000000000003,250.00000000000003,250.00000000000003,500.00000000000006,250.00000000000003,250.00000000000003,500.00000000000006,1000.0000000000001,1000.0000000000001,500.00000000000006,250.00000000000003,250.00000000000003,250.00000000000003,250.00000000000003,250.00000000000003,250.00000000000003,1500.0,500.00000000000006,500.00000000000006,250.00000000000003,250.00000000000003,250.00000000000003,250.00000000000003,250.00000000000003,250.00000000000003,1500.0,500.00000000000006,500.00000000000006,250.00000000000003,250.00000000000003,250.00000000000003,250.00000000000003,250.00000000000003,250.00000000000003,250.00000000000003,250.00000000000003,250.00000000000003,250.00000000000003,250.00000000000003,250.00000000000003,250.00000000000003,250.00000000000003,250.00000000000003,250.00000000000003,500.00000000000006,250.00000000000003,250.00000000000003,500.00000000000006,1000.0000000000001,1000.0000000000001,500.00000000000006,875.0000000000001,125.00000000000001,250.00000000000003,250.00000000000003,1000.0000000000001,};
int melody_size = 98;

//de chapeu de sol aberto 
int notes2[] = {NOTE_,NOTE_D4,NOTE_B3,NOTE_G3,NOTE_B3,NOTE_D4,NOTE_C4,NOTE_A3,NOTE_D4,NOTE_B3,NOTE_G3,NOTE_D4,NOTE_B3,NOTE_G3,NOTE_D4,NOTE_C4,NOTE_A3,NOTE_E4,NOTE_D4,NOTE_,NOTE_G4,NOTE_,NOTE_,NOTE_,NOTE_D4,NOTE_E4,NOTE_D4,NOTE_B4,NOTE_,NOTE_A4,NOTE_,NOTE_G4,NOTE_,NOTE_D4,NOTE_B3,NOTE_G3,NOTE_B3,NOTE_D4,NOTE_C4,NOTE_A3,NOTE_D4,NOTE_B3,NOTE_G3,NOTE_D4,NOTE_B3,NOTE_G3,NOTE_D4,NOTE_C4,NOTE_A3,NOTE_E4,NOTE_D4,NOTE_,NOTE_G4,NOTE_,NOTE_,NOTE_,NOTE_D4,NOTE_E4,NOTE_D4,NOTE_B4,NOTE_,NOTE_A4,NOTE_,NOTE_G4,NOTE_,NOTE_B3,NOTE_A3,NOTE_G3,NOTE_F3,NOTE_E3,NOTE_D3,NOTE_C4,NOTE_,NOTE_G3,NOTE_A3,NOTE_G3,NOTE_G3,NOTE_,NOTE_F3,NOTE_E3,NOTE_D4,NOTE_C4,NOTE_G4,NOTE_G4,NOTE_G4,NOTE_G4,NOTE_G4,NOTE_,NOTE_G4,NOTE_,NOTE_,NOTE_,NOTE_G4,NOTE_G4,NOTE_G4,NOTE_,NOTE_G4,NOTE_,NOTE_F4,NOTE_,NOTE_,NOTE_,NOTE_B3,NOTE_C4,NOTE_D4,NOTE_E4,NOTE_D4,NOTE_C4,NOTE_D4,NOTE_E4,NOTE_,NOTE_D4,NOTE_E4,NOTE_F4,NOTE_G4,NOTE_A4,NOTE_A4,NOTE_F4,NOTE_,NOTE_E4,NOTE_D4,NOTE_C4,NOTE_C4,NOTE_B3,NOTE_A3,NOTE_E4,NOTE_D4,NOTE_B3,NOTE_G3,};
int durations2[] = {125.00000000000001,250.00000000000003,125.00000000000001,125.00000000000001,250.00000000000003,125.00000000000001,250.00000000000003,250.00000000000003,250.00000000000003,375.0,250.00000000000003,125.00000000000001,125.00000000000001,250.00000000000003,125.00000000000001,250.00000000000003,250.00000000000003,250.00000000000003,437.50000000000006,62.50000000000001,250.00000000000003,500.00000000000006,1000.0000000000001,250.00000000000003,125.00000000000001,125.00000000000001,250.00000000000003,250.00000000000003,250.00000000000003,250.00000000000003,250.00000000000003,250.00000000000003,125.00000000000001,250.00000000000003,125.00000000000001,125.00000000000001,250.00000000000003,125.00000000000001,250.00000000000003,250.00000000000003,250.00000000000003,375.0,250.00000000000003,125.00000000000001,125.00000000000001,250.00000000000003,125.00000000000001,250.00000000000003,250.00000000000003,250.00000000000003,437.50000000000006,62.50000000000001,250.00000000000003,500.00000000000006,1000.0000000000001,250.00000000000003,125.00000000000001,125.00000000000001,250.00000000000003,250.00000000000003,250.00000000000003,250.00000000000003,250.00000000000003,250.00000000000003,125.00000000000001,250.00000000000003,125.00000000000001,125.00000000000001,250.00000000000003,125.00000000000001,250.00000000000003,500.00000000000006,250.00000000000003,333.33333333333337,333.33333333333337,333.33333333333337,750.0,250.00000000000003,750.0,750.0,500.00000000000006,250.00000000000003,125.00000000000001,125.00000000000001,125.00000000000001,125.00000000000001,250.00000000000003,250.00000000000003,250.00000000000003,500.00000000000006,250.00000000000003,125.00000000000001,125.00000000000001,250.00000000000003,250.00000000000003,250.00000000000003,250.00000000000003,250.00000000000003,2000.0000000000002,250.00000000000003,250.00000000000003,125.00000000000001,125.00000000000001,125.00000000000001,125.00000000000001,375.0,125.00000000000001,125.00000000000001,125.00000000000001,500.00000000000006,250.00000000000003,125.00000000000001,125.00000000000001,125.00000000000001,125.00000000000001,375.0,125.00000000000001,250.00000000000003,500.00000000000006,333.33333333333337,333.33333333333337,333.33333333333337,333.33333333333337,333.33333333333337,333.33333333333337,250.00000000000003,250.00000000000003,250.00000000000003,250.00000000000003,};
int melody_size2 = 129;

//cala boca menino
int notes3[] = {NOTE_,NOTE_G4,NOTE_G4,NOTE_F4,NOTE_E4,NOTE_C4,NOTE_,NOTE_E4,NOTE_,NOTE_C4,NOTE_F4,NOTE_,NOTE_E4,NOTE_D4,NOTE_,NOTE_E4,NOTE_F4,NOTE_G4,NOTE_D4,NOTE_G4,NOTE_,NOTE_G4,NOTE_F4,NOTE_E4,NOTE_C4,NOTE_,NOTE_,NOTE_G4,NOTE_F4,NOTE_E4,NOTE_C4,NOTE_,NOTE_E4,NOTE_,NOTE_C4,NOTE_F4,NOTE_,NOTE_E4,NOTE_D4,NOTE_,NOTE_E4,NOTE_F4,NOTE_G4,NOTE_D4,NOTE_G4,NOTE_,NOTE_G4,NOTE_F4,NOTE_E4,NOTE_C4,NOTE_,NOTE_,NOTE_F4,NOTE_F4,NOTE_F4,NOTE_G4,NOTE_A4,NOTE_F4,NOTE_A4,NOTE_,NOTE_F4,NOTE_,NOTE_G4,NOTE_G4,NOTE_G4,NOTE_G4,NOTE_G4,NOTE_G4,NOTE_A4,NOTE_B4,NOTE_,NOTE_G4,NOTE_G4,NOTE_,NOTE_G4,NOTE_D4,NOTE_,};
int durations3[] = {125.00000000000001,250.00000000000003,125.00000000000001,250.00000000000003,250.00000000000003,500.00000000000006,250.00000000000003,437.50000000000006,62.50000000000001,250.00000000000003,250.00000000000003,125.00000000000001,125.00000000000001,1000.0000000000001,500.00000000000006,250.00000000000003,250.00000000000003,500.00000000000006,250.00000000000003,437.50000000000006,62.50000000000001,250.00000000000003,250.00000000000003,250.00000000000003,750.0,250.00000000000003,250.00000000000003,250.00000000000003,250.00000000000003,250.00000000000003,500.00000000000006,250.00000000000003,437.50000000000006,62.50000000000001,250.00000000000003,250.00000000000003,125.00000000000001,125.00000000000001,1000.0000000000001,500.00000000000006,250.00000000000003,250.00000000000003,500.00000000000006,250.00000000000003,437.50000000000006,62.50000000000001,250.00000000000003,250.00000000000003,250.00000000000003,750.0,250.00000000000003,1000.0000000000001,250.00000000000003,250.00000000000003,250.00000000000003,250.00000000000003,500.00000000000006,250.00000000000003,437.50000000000006,62.50000000000001,1000.0000000000001,250.00000000000003,250.00000000000003,250.00000000000003,500.00000000000006,250.00000000000003,250.00000000000003,500.00000000000006,250.00000000000003,500.00000000000006,250.00000000000003,125.00000000000001,125.00000000000001,250.00000000000003,250.00000000000003,500.00000000000006,250.00000000000003,};
int melody_size3 = 77;

//sabe la o que e isso
int notes4[] = {NOTE_,NOTE_G4,NOTE_G4,NOTE_F4,NOTE_E4,NOTE_C4,NOTE_,NOTE_E4,NOTE_,NOTE_C4,NOTE_F4,NOTE_,NOTE_E4,NOTE_D4,NOTE_,NOTE_E4,NOTE_F4,NOTE_G4,NOTE_D4,NOTE_G4,NOTE_,NOTE_G4,NOTE_F4,NOTE_E4,NOTE_C4,NOTE_,NOTE_,NOTE_G4,NOTE_F4,NOTE_E4,NOTE_C4,NOTE_,NOTE_E4,NOTE_,NOTE_C4,NOTE_F4,NOTE_,NOTE_E4,NOTE_D4,NOTE_,NOTE_E4,NOTE_F4,NOTE_G4,NOTE_D4,NOTE_G4,NOTE_,NOTE_G4,NOTE_F4,NOTE_E4,NOTE_C4,NOTE_,NOTE_,NOTE_F4,NOTE_F4,NOTE_F4,NOTE_G4,NOTE_A4,NOTE_F4,NOTE_A4,NOTE_,NOTE_F4,NOTE_,NOTE_G4,NOTE_G4,NOTE_G4,NOTE_G4,NOTE_G4,NOTE_G4,NOTE_A4,NOTE_B4,NOTE_,NOTE_G4,NOTE_G4,NOTE_,NOTE_G4,NOTE_D4,NOTE_,NOTE_,NOTE_G4,NOTE_G4,NOTE_G4,NOTE_G4,NOTE_G4,NOTE_G4,NOTE_D4,NOTE_G4,NOTE_G4,NOTE_G4,NOTE_G4,NOTE_A4,NOTE_B4,NOTE_C5,NOTE_,NOTE_,NOTE_C5,};
int durations4[] = {125.00000000000001,250.00000000000003,125.00000000000001,250.00000000000003,250.00000000000003,500.00000000000006,250.00000000000003,437.50000000000006,62.50000000000001,250.00000000000003,250.00000000000003,125.00000000000001,125.00000000000001,1000.0000000000001,500.00000000000006,250.00000000000003,250.00000000000003,500.00000000000006,250.00000000000003,437.50000000000006,62.50000000000001,250.00000000000003,250.00000000000003,250.00000000000003,750.0,250.00000000000003,250.00000000000003,250.00000000000003,250.00000000000003,250.00000000000003,500.00000000000006,250.00000000000003,437.50000000000006,62.50000000000001,250.00000000000003,250.00000000000003,125.00000000000001,125.00000000000001,1000.0000000000001,500.00000000000006,250.00000000000003,250.00000000000003,500.00000000000006,250.00000000000003,437.50000000000006,62.50000000000001,250.00000000000003,250.00000000000003,250.00000000000003,750.0,250.00000000000003,1000.0000000000001,250.00000000000003,250.00000000000003,250.00000000000003,250.00000000000003,500.00000000000006,250.00000000000003,437.50000000000006,62.50000000000001,1000.0000000000001,250.00000000000003,250.00000000000003,250.00000000000003,500.00000000000006,250.00000000000003,250.00000000000003,500.00000000000006,250.00000000000003,500.00000000000006,250.00000000000003,125.00000000000001,125.00000000000001,250.00000000000003,250.00000000000003,500.00000000000006,250.00000000000003,250.00000000000003,125.00000000000001,125.00000000000001,250.00000000000003,125.00000000000001,125.00000000000001,250.00000000000003,500.00000000000006,250.00000000000003,250.00000000000003,125.00000000000001,125.00000000000001,250.00000000000003,250.00000000000003,250.00000000000003,250.00000000000003,250.00000000000003,437.50000000000006,};
int melody_size4 = 95;

int inputPin = 13;               // choose the input pin (for PIR sensor)
int pirState = LOW;             // we start, assuming no motion detected
int val = 0;                    // variable for reading the pin status

int pinOut = 9;
int freq = 200;
int duration = 500;

int aux = true;

void setup() {
  //pinMode(ledPin, OUTPUT);      // declare LED as output
  pinMode(inputPin, INPUT);     // declare sensor as input
  servo1.attach(4); //configura um servomotor na porta digital 5
  Serial.begin(9600);
}

void loop(){
  val = digitalRead(inputPin);  // read input value
  //Serial.println(val);
  //tone(pinOut, freq, duration);
  //return;
  
  if (aux){
    val = LOW;
    servo1.write(-80);
    aux = !aux;
  }
  
  if (val == HIGH) {            // check if the input is HIGH
    tone(pinOut, freq, duration);
    //digitalWrite(ledPin, HIGH);  // turn LED ON
    
    if (pirState == LOW) {
      // we have just turned on
            
      Serial.println("Motion detected!");
      // move o o servo em 90 em seu  eixo
      servo1.write(90);
      delay(7000);
      

      // We only want to print on the output change, not state
      pirState = HIGH;
    }
  } 
  else {
    //digitalWrite(ledPin, LOW); // turn LED OFF
    if (pirState == HIGH){
      servo1.write(-80);
      // we have just turned of
      Serial.println("Motion ended!");
       // move o  servo -90 par tras em seu  eixo
      

      // We only want to print on the output change, not state
      pirState = LOW;
      
      switch (TrueRandom.random(1,5))
      {
        case 1:
        //vassourinhas
        {
          for (int thisNote = 0; thisNote < melody_size + 1; thisNote++) {
    
          int noteDuration = durations[thisNote];
          tone(9, notes[thisNote], noteDuration);
      
          delay(noteDuration - 100);
          noTone(9);
          }
          break;         
        }
        
        case 2:
        //de chapeu de sol aberto
        {
          for (int thisNote2 = 0; thisNote2 < melody_size2 + 1; thisNote2++) {
        
            int noteDuration2 = durations2[thisNote2];
            tone(9, notes2[thisNote2],noteDuration2);
        
            delay(noteDuration2);
            noTone(9);
          }
        
          delay (100);
          break;
        }
        
        case 3:
        //cala boca menino
        {
          for (int thisNote3 = 0; thisNote3 < melody_size3 + 1; thisNote3++) {
        
            int noteDuration3 = durations3[thisNote3];
            tone(9, notes3[thisNote3],noteDuration3);
        
            delay(noteDuration3);
            noTone(9);
          }
        
          delay (100);
          break;
        }
        
        case 4:
        //sabe la o que e isso
        {
          for (int thisNote4 = 0; thisNote4 < melody_size4 + 1; thisNote4++) {
        
            int noteDuration4 = durations4[thisNote4];
            tone(9, notes4[thisNote4],noteDuration4);
        
            delay(noteDuration4);
            noTone(9);
          }
        
          delay (100);
          break;
        }
      }
      
      }
    }
  }
