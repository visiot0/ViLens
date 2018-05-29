/* Postavka */
#include<NewPing.h>
#include<String.h>
const int leftTriggerPin = 6;
const int leftEchoPin = 7;
const int frontTriggerPin = 8;
const int frontEchoPin = 9;
const int rightTriggerPin = 11;
const int rightEchoPin = 10;

//varijable
float vrijednost = 150;
float vrijednostLR=120;
float maxGledanaUdaljenost = 200.00;
float frontDuration, frontDistanceCm, leftDuration, leftDistanceCm,rightDistanceCm,rightDuration,normalnaVisina,brojac=0,razlika,suma1=0,suma2=0,h1,h2,r=4.2,l1,l2,l3,rw=20,s=20;
String smjer;
int frontUdaljenostMjera,leftUdaljenostMjera,rightUdaljenostMjera;
void setup() {
  pinMode(frontTriggerPin,OUTPUT);
  pinMode(frontEchoPin,INPUT);
  pinMode(rightTriggerPin,OUTPUT);
  pinMode(rightEchoPin,INPUT);
  pinMode(leftTriggerPin,OUTPUT);
  pinMode(leftEchoPin,INPUT);
  Serial.begin(9600);
}

void loop() {
  leftUdaljenost();
  delay(50);
  rightUdaljenost();
  delay(50);
  frontUdaljenost();
  delay(50);
  h1=(leftDistanceCm/2)+21;
  h2=(rightDistanceCm/2)+21;
  l1=leftDistanceCm*0.866-5.63;
  l2=(rightDistanceCm-leftDistanceCm)*0.866;
  l3=(frontDistanceCm-rightDistanceCm)*0.866-5.63;
  if((h1>rw+s) && (h2>rw+s))
  {
    smjer="P";
    Serial.print(smjer);
    Serial.print("|");
    //mozete nastaviti naprijed
   }
   else if(leftDistanceCm>rightDistanceCm)
   {
    smjer="P1";
    Serial.print(smjer);
    Serial.print("|");
    //skrenite lijevo da izbjegnete prepreku
   }
   else if(rightDistanceCm>leftDistanceCm)
   {
    smjer="P2";
   Serial.print(smjer);
   Serial.print("|");
    //skrenite desno da izbjegnete prepreku
   }
  }
 void leftUdaljenost(){
   do{
    NewPing sonar(leftTriggerPin, leftEchoPin, maxGledanaUdaljenost); 
    leftDistanceCm=sonar.ping_cm();
  }while(leftDistanceCm==0);
 }
  void rightUdaljenost(){
   do{
    NewPing sonar(rightTriggerPin, rightEchoPin, maxGledanaUdaljenost); 
    rightDistanceCm=sonar.ping_cm();
  }while(rightDistanceCm==0);
}
void frontUdaljenost(){
   do{
    NewPing sonar(frontTriggerPin, frontEchoPin, maxGledanaUdaljenost); 
    frontDistanceCm=sonar.ping_cm();
  }while(frontDistanceCm==0);
}
