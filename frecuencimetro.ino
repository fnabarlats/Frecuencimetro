/*************************************************
Frecuencimetro para Receptor Aeronautico

Este Frecuencimetro trabaja midiendo la
tension del VCO local y asociando dicha
tension a la frecuencia de recepcion

Implementado con:
- Arduino UNO
- Receptor Aeronautico basado en NE602 y BB910

Soporte:
- fnabarlats@gmail.com

2017, Desarrollado para alumnos del CIATA
*************************************************/

#define PinTension A0             //PIN del arduino donde inyecto la tension a medir

void setup(){
  Serial.begin(9600);             //Inicializo el puerto serial en 9600 baudios
}

void loop(){

  /* La funcion map() me permite reasignar el rango de valores leidos por la
  entrada analogica a los valores reales de tension que estoy midiendo.
  Recordemos que el puerto analogico mide tensiones de 0 a 5v con una
  resolucion de 1024 bits. Donde bit 1024 corresponde a los 5v */
  medicion = map(analogRead(PinTension),166,824,83,403);

  /* Luego divido el valor por 100 para obtener un numero decimal y
  lo multiplico por 2 ya que la tension que estoy leyendo es la mitad
  de la de VCO, porque lo hice pasar por un divisor resistivo */
  TensionVCO = (medicion/100)*2;

  // Muestro en pantalla la tension de VCO
  Serial.print("Tension de VCO: ");
  Serial.print(TensionVCO);
  Serial.println(" v");

  /* Esta formula de frecuencia la obtengo de la relacion entre la tension medida
  y la frecuencia de recepcion. (consultar Excel con mediciones)*/
  Frecuencia =  -(pow(TensionVCO,2)*0.222) + (5.0276*TensionVCO) +109.91;

  // Muestro en pantalla la frecuencia
  Serial.print("Frecuencia: ");
  Serial.print(Frecuencia);
  Serial.println(" MHz");

  // Retardo de 1 segundo en el programa 
  delay(1000);
}
