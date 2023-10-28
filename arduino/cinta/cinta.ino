/* Este código controla una cinta transportadora mediante un driver TB6600, utilizando
 una fotorresistencia en su entrada.
 Los pines utilizados son el pin de paso (stepPin),
  el pin de habilitación (enaPin), 
  el pin de la fotorresistencia (fotoResistenciaPin) 
  y el pin para enviar la señal al robot (robot).
*/
const int stepPin = 5;               // Pin para el control del paso del motor.
const int enaPin = 8;                // Pin para habilitar o deshabilitar el motor.
const int fotoResistenciaPin = A0;   // Pin para la lectura de la fotorresistencia.
const int robot = 2;                 // Pin para controlar el robot.

int lectura;             // Variable para almacenar la lectura de la fotorresistencia.
int valorMapeado;        // Variable para almacenar el valor mapeado de la lectura.

void setup() {
  pinMode(stepPin, OUTPUT);      // Configura el pin de paso como salida.
  pinMode(enaPin, OUTPUT);       // Configura el pin de habilitación como salida.
  pinMode(robot, OUTPUT);        // Configura el pin de control del dispositivo como salida.
}

void loop() {
  digitalWrite(enaPin, LOW);  // Habilita el motor inicialmente.
  lectura = analogRead(fotoResistenciaPin);  // Lee el valor de la fotorresistencia.
  valorMapeado = map(lectura, 0, 1023, 0, 255);  // Mapea el valor leído.

  digitalWrite(robot, LOW);  // Apaga el dispositivo controlado por el pin 'robot'.

  if (valorMapeado > 128) {  // Si incide el láser.
    digitalWrite(stepPin, HIGH);          // Activa el paso del motor.
    delayMicroseconds(500);
    digitalWrite(stepPin, LOW);
    delayMicroseconds(500);
  } else if (valorMapeado < 128) {  // Si no incide el láser.
    digitalWrite(enaPin, HIGH);    // Deshabilita el motor.
    digitalWrite(robot, HIGH);     // Enciende el dispositivo controlado por el pin 'robot'.
  }
}

