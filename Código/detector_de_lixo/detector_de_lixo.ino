
int dif = 100;
int dia = 600;
int noite = 300;
int sub ;
int ldr = A0;
int emissor = 7;
int led = 8;
int leitura;
boolean claro;
boolean escuro;
void setup(){
  Serial.begin(9600);
   pinMode(emissor,OUTPUT);
   pinMode(led,OUTPUT);
}
void loop(){
   leitura = analogRead(ldr);
    Serial.println(leitura);
    digitalWrite(emissor,HIGH);
//    delay(500);
sub  = leitura - dif; 
Serial.println("sub");
Serial.println(sub);
  if (leitura>= dia){
     claro = true;
     escuro = false;  
    }
    if (leitura <= noite){
        claro = false;
        escuro = true;  

      }

      if (claro == true){
        if (leitura<dia){
          digitalWrite(led,HIGH);
          delay(500); 
          digitalWrite(led,LOW);
         }
       }
       if(noite==true){
          if (leitura<noite){
           digitalWrite(led,HIGH);
           delay(500);
           digitalWrite(led,LOW);
           }
        }

}

//esquerda -, direita +
