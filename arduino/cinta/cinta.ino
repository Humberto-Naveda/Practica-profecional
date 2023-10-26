#include <Servo.h>

Servo myservo;  
Servo myservo2;  

const int Cerrar = 2;
const int Abrir = 3;
const int stepPin = 5;
const int dirPin = 4;
const int enPin = 8;
const int fotoResistenciaPin = A0;
const int robot= 6;

int lectura;
int  valorMapeado;


int pos;   
int pos2;

void setup() {
  pinMode(stepPin,OUTPUT);
  pinMode(dirPin,OUTPUT);
  pinMode(enPin,OUTPUT);
  pinMode(robot,OUTPUT);
  pinMode(Cerrar, INPUT);
  pinMode(Abrir, INPUT);
  myservo.attach(9);  
  myservo.write(0);// (0 /45) - 20(cubo)
  myservo2.attach(7);  
  myservo2.write(180);// (180 / 135) - 160(cubo)
}

void loop() {

 digitalWrite(dirPin,HIGH);
 digitalWrite(enPin,LOW);
 lectura = analogRead(fotoResistenciaPin);
 valorMapeado = map(lectura, 0, 1023, 0, 255);
 digitalWrite(robot,LOW);
       

 if(valorMapeado < 128){       //incide laser
  digitalWrite(stepPin,HIGH);
  delayMicroseconds(500);
  digitalWrite(stepPin,LOW);
  delayMicroseconds(500);
  }
  else if(valorMapeado > 128){ // no laser
       pos = 10;   
       pos2 = 180;
       digitalWrite(enPin,HIGH);
       digitalWrite(robot,HIGH);
       
     if(digitalRead (2)== HIGH){  //CERRAR
      myservo.write(20);
      myservo2.write(160);
     }else  if (digitalRead (3) == HIGH){ //ABRIR
        
        myservo.write(0);
        myservo2.write(180);
       
        }
        
  }
  }
