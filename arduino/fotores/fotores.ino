const int fotoResistenciaPin = A0;  // Pin analógico utilizado para la foto resistencia

void setup() {
  Serial.begin(9600);  // Iniciar comunicación serial a 9600 bps
}

void loop() {
  int lectura = analogRead(fotoResistenciaPin);  // Leer valor de la foto resistencia
  int valorMapeado = map(lectura, 0, 1023, 0, 255);  // Mapear valor leído a un rango de 0 a 255
  
  Serial.print("Lectura original: ");
  Serial.println(lectura);
  Serial.print(" | Valor mapeado: ");
  Serial.println(valorMapeado);
  
  // Realizar acciones en función del valor mapeado
  
  delay(1500);  // Esperar medio segundo antes de realizar la siguiente lectura
}
