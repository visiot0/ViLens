/* Postavka */
#include<NewPing.h>
#include<String.h>
const int leftTriggerPin = 6;
const int leftEchoPin = 7;
const int frontTriggerPin = 8;
const int frontEchoPin = 9;
const int rightTriggerPin = 10;
const int rightEchoPin = 11;

//varijable
float vrijednost = 80;
float vrijednostLR=120;
float maxGledanaUdaljenost = 350.00;
float frontDuration, frontDistanceCm, leftDuration, leftDistanceCm,rightDistanceCm,rightDuration,normalnaVisina,brojac=0,razlika,suma1=0,suma2=0,h1,h2,r=4.2,L1,L2,a,b,c,sw=60;
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
  if(leftDistanceCm>20 && rightDistanceCm>20)
  {
    razlika=rightDistanceCm-leftDistanceCm;
  if(rightDistanceCm>vrijednostLR && leftDistanceCm>vrijednostLR)
  {
    smjer="P";
    if(smjer.length()!=0)
    {
    Serial.print(smjer);
    Serial.print("|");
    }
    
    //nemate nista pred sobom mozete ici pravo
  }
  else if((rightDistanceCm<vrijednostLR && leftDistanceCm<vrijednostLR)  && (razlika>-20&& razlika<20))
  {
    h1=(leftDistanceCm+r)*sin(15);
    h2=(rightDistanceCm+r)*sin(15):
    c=h1+h2;
    if(c>=sw)
    {
      smjer="P";
    if(smjer.length()!=0)
    {
    Serial.print(smjer);
    Serial.print("|");
    }
    else
    {
       smjer="P0";
      Serial.print(smjer);
      Serial.print("|");
     //imate ispred sebe nesta
    }
    }
   
  }
  else
  {
    if(rightDistanceCm>leftDistanceCm)
    {
      //desna strana vam je slobodna
      //imate objekat sa lijeve
       smjer="P2";
        Serial.print(smjer);
        Serial.print("|");
    }
    else if(leftDistanceCm>rightDistanceCm)
    {
       //s desne strane imate objekat
        //lijeva strana vam je slobodna
      smjer="P1";
        Serial.print(smjer);
        Serial.print("|");
    }
  }
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
