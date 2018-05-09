/* Postavka */
#include<NewPing.h>
const int leftTriggerPin = 6;
const int leftEchoPin = 7;
const int frontTriggerPin = 8;
const int frontEchoPin = 9;
const int rightTriggerPin = 10;
const int rightEchoPin = 11;


//varijable
 float maxFrontUdaljenost = 100.00;
float frontDuration, frontDistanceCm, leftDuration, leftDistanceCm,rightDistanceCm,rightDuration,normalnaVisina,brojac=0;
void NormalnaVisina()
{
  float suma=0;
  for(int i=0;i<100;i++)
  {  
  NewPing sonar(frontTriggerPin, frontEchoPin, 200); 
  if(sonar.ping_cm()!=0)
     {
      suma+=sonar.ping_cm();
      brojac++;
     }
  }
  normalnaVisina=suma/brojac;
}

void setup() {
  pinMode(frontTriggerPin,OUTPUT);
  pinMode(frontEchoPin,INPUT);
  pinMode(rightTriggerPin,OUTPUT);
  pinMode(rightEchoPin,INPUT);
  pinMode(leftTriggerPin,OUTPUT);
  pinMode(leftEchoPin,INPUT);
  NormalnaVisina();
  Serial.begin(9600);
}

void loop() {
 
  frontUdaljenost();
  float vrijednostVisina=frontDistanceCm-normalnaVisina;
  if(vrijednostVisina>5)
  {
    Serial.print(vrijednostVisina);
    Serial.println("PREPREKA-PAZI");
  }
  else if(vrijednostVisina<-5)
  {
    Serial.print(vrijednostVisina);
    Serial.println("IDETE DOLE");
  }
  else{
    Serial.println("OK JE");
  }
 
  
  
}
void frontUdaljenost(){
  do{
    NewPing sonar(frontTriggerPin, frontEchoPin, 200); 
    frontDistanceCm=sonar.ping_cm();
  }while(frontDistanceCm==0);
 }

 void leftUdaljenost(){
  digitalWrite(leftTriggerPin, LOW);  
  delayMicroseconds(4);
  digitalWrite(leftTriggerPin, HIGH);  
  delayMicroseconds(10);
  digitalWrite(leftTriggerPin, LOW);
  leftDuration = pulseIn(leftEchoPin, HIGH);  
  leftDistanceCm = leftDuration * 10 / 292 / 2;
  /* Serial.print("Udaljenost: ");
  Serial.print(leftDistanceCm);
  Serial.println(" cm");*/
 }
  void rightUdaljenost(){
  digitalWrite(rightTriggerPin, LOW);  
  delayMicroseconds(4);
  digitalWrite(rightTriggerPin, HIGH);  
  delayMicroseconds(10);
  digitalWrite(rightTriggerPin, LOW);
  rightDuration = pulseIn(rightEchoPin, HIGH);  
  rightDistanceCm = rightDuration * 10 / 292 / 2;
  /*  Serial.print("Udaljenost: ");
  Serial.print(rightDistanceCm);
  Serial.println(" cm");*/
 }
