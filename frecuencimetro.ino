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

#define PinTension A0;

void setup(){
  Serial.setup(9600);
}

void loop(){

  float TensionVCO, TensionVCOanterior;

  if (TensionVCO != TensionVCOanterior){
    Serial.print("Tension de VCO: ");
    Serial.println(TensionVCO);
  }

}
