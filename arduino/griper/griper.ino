#include <Servo.h>
/* "El siguiente código se ha diseñado con el propósito de controlar la apertura y cierre de un gripper 
a través de las señales emitidas por un relé. El pin 2 del dispositivo recibe la señal procedente del 
contacto normalmente abierto (NO) del relé, lo que permite activar la acción de cerrar el gripper. P
or otro lado, el pin 3 recibe la señal desde el contacto normalmente cerrado (NC) del relé, 
lo que posibilita la operación de apertura del gripper."
*/

Servo myservo;  
Servo myservo2; 

const int Cerrar = 2;  // Pin para cerrar.
const int Abrir = 3;   // Pin para abrir.

int pos = 0;           // Variable para la posición del servo 1.
int pos2 = 180;         // Variable para la posición del servo 2.

void setup() {
  pinMode(Cerrar, INPUT);  // Configurar el pin Cerrar como entrada.
  pinMode(Abrir, INPUT);   // Configurar el pin Abrir como entrada.
  
  myservo.attach(9);     // Adjuntar servo 1 al pin 9.
  myservo.write(0);      // Inicializar servo 1 en posición 0 grados.
  
  myservo2.attach(7);    // Adjuntar servo 2 al pin 7.
  myservo2.write(180);   // Inicializar servo 2 en posición 180 grados.
  
  Serial.begin(9600);    // Iniciar comunicación serial a 9600 baudios.
}

void loop() {
  if (digitalRead(Cerrar) == HIGH) {  // Si la señal Cerrar está en alto.
    myservo.write(30);               // Mover servo 1 a posición 30 grados.
    myservo2.write(160);             // Mover servo 2 a posición 160 grados.
  } else if (digitalRead(Abrir) == HIGH) {  // Si la señal Abrir está en alto.
    myservo.write(10);               // Mover servo 1 a posición 10 grados.
    myservo2.write(180);              // Mover servo 2 a posición 180 grados.
  }
}
