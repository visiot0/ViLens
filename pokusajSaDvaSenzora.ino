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
float frontDuration, frontDistanceCm, leftDuration, leftDistanceCm,rightDistanceCm,rightDuration,normalnaVisina,brojac=0,razlika,suma1=0,suma2=0;
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
  else if((rightDistanceCm<vrijednostLR && leftDistanceCm<vrijednostLR)  && (razlika>-35&& razlika<35))
  {
    smjer="P0";
      Serial.print(smjer);
      Serial.print("|");
   /* if(rightDistanceCm<100 && leftDistanceCm<100)
    {
      if(rightDistanceCm>leftDistanceCm)
      {
        //s lijeve strane imate objekat
        //desna strana vam je slobodna
        for(int i=0;i<3;i++)
        {
          smjer="P2";
        Serial.print(smjer);
        delay(50);
        Serial.print("|");
        }
        
      }
      else
      {
        //s desne strane imate objekat
        //lijeva strana vam je slobodna
        for(int i=0;i<3;i++)
        {
          smjer="P1";
        Serial.print(smjer);
        delay(50);
        Serial.print("|");
        } 
      }
    }
    else if(rightDistanceCm>100 && rightDistanceCm>leftDistanceCm)
    {
      //desna strana vam je slobodna
      //imate objekat sa lijeve
       smjer="P2";
        Serial.print(smjer);
        delay(50);
        Serial.print("|");
    }
    else if(leftDistanceCm>100 && leftDistanceCm>rightDistanceCm)
    {
       //s desne strane imate objekat
        //lijeva strana vam je slobodna
      smjer="P1";
        Serial.print(smjer);
        delay(50);
        Serial.print("|");
    }*/
     //imate ispred sebe nesta
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
 //delay(350);
  //delay(50);
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
