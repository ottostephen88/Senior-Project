#include <Servo.h>
 
Servo myservo;  
Servo myservo2;
                
int angle; 
int angle2;

//global variables
const int Relay_Enable = 2;
const int Relay2_Enable = 3;
const int RelayActuation_Enable = 6;

char letter='r';



void setup() {

  myservo.attach(9);  
  myservo2.attach(10);  
  pinMode(Relay_Enable,OUTPUT);
  pinMode(Relay2_Enable,OUTPUT);
  pinMode(RelayActuation_Enable,OUTPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  if(letter=='r')
  {
    Serial.print(letter) ; 
    angle=45;
    angle2=135;
    
  }
  else if(letter=='l')
  {
    Serial.print(letter) ;
    angle=135;
    angle2=45; 
  }
  else if(letter=='s')
  {
    Serial.print(letter) ;
    angle=90;
    angle2=90; 
  }
  else if(letter=='u')
  {
    Serial.print(letter) ;
    angle=45;
    angle2=45; 
  }
  else if(letter=='d')
  {
    Serial.print(letter) ;
    angle=135;
    angle2=135; 
  }
  myservo.write(angle);
  myservo2.write(angle2);
//buoyancy
Serial.println("Relay ON");
digitalWrite(Relay_Enable,LOW);
delay(1000);

Serial.println("Relay OFF");
digitalWrite(Relay_Enable,HIGH);
delay(1000);

Serial.println("Relay ON");
digitalWrite(Relay2_Enable,LOW);
delay(1000);

Serial.println("Relay OFF");
digitalWrite(Relay2_Enable,HIGH);
delay(1000);

//actuation

Serial.println("Relay Off");
digitalWrite(RelayActuation_Enable,LOW);
delay(1000);

Serial.println("Relay ON");
digitalWrite(RelayActuation_Enable,HIGH);
delay(1000);

}
