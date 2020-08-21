//Programa: Conectando Sensor Ultrassonico HC-SR04 ao Arduino
//Autor: FILIPEFLOP
 
//Carrega a biblioteca do sensor ultrassonico
#include <Ultrasonic.h>
 
//Define os pinos para o trigger e echo
#define pino_trigger 4
#define pino_echo 5
 
//Inicializa o sensor nos pinos definidos acima
Ultrasonic ultrasonic(pino_trigger, pino_echo);

bool label = true;

void setup()
{
  Serial.begin(9600);
  
}
 
void loop()
{
    //print out column headers
    while(label){ //runs once
        Serial.print("Distancia em cm");
        Serial.print(",");
        Serial.print("Distancia em polegadas\n");
        label=false;
  }
  //Le as informacoes do sensor, em cm e pol
  float cmMsec, inMsec;
  long microsec = ultrasonic.timing();
  cmMsec = ultrasonic.convert(microsec, Ultrasonic::CM);
  inMsec = ultrasonic.convert(microsec, Ultrasonic::IN);
  //Exibe informacoes no serial monitor
  
  Serial.print(cmMsec);
  Serial.print(",");
  Serial.println(inMsec);
  delay(1000);
}
