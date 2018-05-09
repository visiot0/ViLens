/* Postavka */

const int leftTriggerPin = 6;
const int leftEchoPin = 7;
const int frontTriggerPin = 8;
const int frontEchoPin = 9;
const int rightTriggerPin = 10;
const int rightEchoPin = 11;


//varijable
 float maxFrontUdaljenost = 100.00;
float frontDuration, frontDistanceCm, leftDuration, leftDistanceCm,rightDistanceCm,rightDuration,distancaSrednjiLijevi,distancaSrednjiDesni;

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
 
   frontUdaljenost();
   leftUdaljenost();
   rightUdaljenost();
  // Serial.println(frontDistanceCm);
   distancaSrednjiLijevi=frontDistanceCm-leftDistanceCm;
      distancaSrednjiDesni=frontDistanceCm-rightDistanceCm;
   if(distancaSrednjiLijevi>-5 and distancaSrednjiLijevi<5)
   {
    float aritmetickaSredina=(frontDistanceCm+leftDistanceCm)/2;
    Serial.print("Udaljenost objekta je ");
     Serial.print(aritmetickaSredina);
      Serial.println("-PREDNJA LIJEVA");
   }
   else if(distancaSrednjiDesni>-5 and distancaSrednjiDesni<5)
   {
    float aritmetickaSredina=(frontDistanceCm+rightDistanceCm)/2;
     Serial.print("Udaljenost objekta je ");
     Serial.print(aritmetickaSredina);
      Serial.println("-PREDNJA DESNA");
   }
 /*  else
   {
    Serial.println(frontDistanceCm);
    Serial.println(rightDistanceCm);
    Serial.println(leftDistanceCm);
    Serial.print("NEMA");
   }*/
   
   /*frontUdaljenost();
   if(frontDistanceCm < maxFrontUdaljenost){
     leftUdaljenost();
     if(leftDistanceCm < maxFrontUdaljenost){
        rightUdaljenost();
        if(rightDistanceCm >= maxFrontUdaljenost){
          Serial.println("DESNO -> -> -> ->");
          }
      } else {
        Serial.println("<- <- <- <- LIJEVO");
    
      }

    } else {
        Serial.println("^^^^ PRAVO ^^^^");  
  
      }*/
  
 
  
  
}

void frontUdaljenost(){
  digitalWrite(frontTriggerPin, LOW);  
  delayMicroseconds(4);
  digitalWrite(frontTriggerPin, HIGH);  
  delayMicroseconds(10);
  digitalWrite(frontTriggerPin, LOW);
  frontDuration = pulseIn(frontEchoPin, HIGH);  
  frontDistanceCm = frontDuration * 10 / 292 / 2;
  Serial.print("Udaljenost: ");
  Serial.print(frontDistanceCm);
  Serial.println(" cm");
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
  Serial.print(frontDistanceCm);
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
   /* Serial.print("Udaljenost: ");
  Serial.print(frontDistanceCm);
  Serial.println(" cm");*/
 }
