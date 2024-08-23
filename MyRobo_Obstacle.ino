#include<Servo.h>
Servo servo;

#define trigPin 3
#define echoPin 5
#define dinamo1 10
#define dinamo2 11
#define tunda 5000
long durasi;
int distance;

void setup() {
  pinMode(dinamo1,OUTPUT);
  pinMode(dinamo2,OUTPUT);
  pinMode(trigPin,OUTPUT);
  pinMode(echoPin,INPUT);
  servo.attach(9);//pin digital arduino
  servo.write(90);//derajat
  }

void loop() {
  digitalWrite(trigPin,LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin,HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin,LOW);
  
durasi=pulseIn(echoPin,HIGH);
distance=(0.034*durasi)/2;

if(distance<=60){    //kejauhan dalam cm
  
  berhenti();
  GerakServoKanan();
  }
  else{
    maju();
    servo.write(90);}
  
  Serial.print("distance:");
    Serial.println(distance);
  
    delay(300);
}

void berhenti(){
  digitalWrite(dinamo1,LOW);
  digitalWrite(dinamo2,LOW);
  }

void maju(){
  digitalWrite(dinamo1,HIGH);
  digitalWrite(dinamo2,HIGH);
  }
  
void kanan(){
  digitalWrite(dinamo1,HIGH);
  digitalWrite(dinamo2,LOW);
  delay(1);
  }

void kiri(){
  digitalWrite(dinamo1,LOW);
  digitalWrite(dinamo2,HIGH);
  delay(1);
  }

void LurusServo(){
  servo.write(90);
  }

void GerakServoKanan(){
  servo.write(0);
  delay(1000);
  digitalWrite(trigPin,LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin,HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin,LOW);
    
durasi=pulseIn(echoPin,HIGH);
distance=(0.034*durasi)/2;

  if (distance <= 60)
  {
    GerakServoKiri();
    }
    else{
    kanan();
      }
  }


void GerakServoKiri(){
  servo.write(180);
  delay(1000);
  digitalWrite(trigPin,LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin,HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin,LOW);
    
durasi=pulseIn(echoPin,HIGH);
distance=(0.034*durasi)/2;

  if (distance <= 20)
  {
    GerakServoKanan();
    }
    else{
    kiri();
      }
  
  }
