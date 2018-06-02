/* Postavka */
#include<NewPing.h>
#include<String.h>
const int leftTriggerPin = 9;
const int leftEchoPin = 8;
const int frontTriggerPin = 8;
const int frontEchoPin = 9;
const int rightTriggerPin = 7;
const int rightEchoPin = 6;

//varijable
float vrijednost = 80;
float vrijednostLR=120;
float maxGledanaUdaljenost = 200.00;
float frontDuration, frontDistanceCm, leftDuration, leftDistanceCm,rightDistanceCm,rightDuration,normalnaVisina,brojac=0,razlika,suma1=0,suma2=0,h1,h2,r=4.2,L1,L2,a,b,c,sw=5;
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
  
  Serial.print(leftDistanceCm);
  Serial.print("---");
  Serial.println(rightDistanceCm);
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
  else if((rightDistanceCm<vrijednostLR && leftDistanceCm<vrijednostLR)  && (razlika>-35&& razlika<35))
  {
      h1=(leftDistanceCm+r)*sin(15);
    h2=(rightDistanceCm+r)*sin(15);
   // Serial.print(h1);
   // Serial.print("---");
    //Serial.println(h2);
    if(h1>h2){
      c=h1-h2;
      } else if(h1<h2){
        c=h2-h1;
        }
   // c=h1+h2;
    //Serial.print("C =");
    //Serial.println(c);
    if(c>sw)
    {
      smjer="P";
    if(smjer.length()!=0)
    {
   Serial.print(smjer);
   Serial.print("|");
    }
    }
    else if(c<sw)
    {
       smjer="P0";
     Serial.print(smjer);
    Serial.print("|");
     //imate ispred sebe nesta
    }
     //imate ispred sebe nesta
  }
  else
    if(rightDistanceCm>leftDistanceCm)
    {
      //desna strana vam je slobodna
      //imate objekat sa lijeve
       smjer="P1";
       Serial.print(smjer);
        Serial.print("|");
    }
    else if(leftDistanceCm>rightDistanceCm)
    {
       //s desne strane imate objekat
        //lijeva strana vam je slobodna
      smjer="P2";
        Serial.print(smjer);
        Serial.print("|");
    }
  
  }
  
  }

  /*
  if(leftDistanceCm>20 && rightDistanceCm>20)
  {
    razlika=leftDistanceCm-rightDistanceCm;
  if(leftDistanceCm>vrijednostLR && rightDistanceCm>vrijednostLR)
  {
      smjer="P";
      if(smjer.length() != 0)
    {
       Serial.print(smjer);
  Serial.print("|");
      }
  }
 else if(razlika<15 && razlika>-15)
  {
    //Serial.println("Uslo");
    if(leftDistanceCm<vrijednostLR || rightDistanceCm<vrijednostLR && (leftDistanceCm>20 && rightDistanceCm>20)){
      smjer="P0";
      if(smjer.length() != 0)
      {
        Serial.print(smjer);
       Serial.print("|");
        }
      }
   
    //imate predmet ispred sebe na 50 cm
  }
  else if(razlika>15 || razlika<-15 && (leftDistanceCm<vrijednostLR || rightDistanceCm<vrijednostLR) && (leftDistanceCm>20 && rightDistanceCm>20))
  {
    if(leftDistanceCm<rightDistanceCm)
    {
      smjer="P2";
      if(smjer.length() != 0)
      {
         Serial.print(smjer);
      Serial.print("|");
        }    
      //s lijeve strane imate objekat
    }
    else if(rightDistanceCm<leftDistanceCm)
    {
      smjer="P1";
      if(smjer.length() != 0)
      {
         Serial.print(smjer);
      Serial.print("|");
        }

      //s desne strane imate objekat
    }
  }
  } */

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
