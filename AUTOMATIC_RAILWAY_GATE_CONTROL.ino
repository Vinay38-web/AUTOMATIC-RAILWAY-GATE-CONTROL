#include<Servo.h>
Servo myservo;
int buzzer=10;
int red=11;
int green=12;
int open_gate=130;
int close_gate=75;
int ir1=2;
int ir2=3;
int ir3=3;
boolean a=true;
boolean b=true;
boolean c=true;
void setup() {
  Serial.begin(9600);
  myservo.attach(6);
  myservo.write(close_gate);
  pinMode(buzzer,OUTPUT);
  pinMode(red,OUTPUT);
  pinMode(green,OUTPUT);
  pinMode(ir1,INPUT);
  pinMode(ir2,INPUT);
  pinMode(ir3,INPUT);
  pinMode(buzzer,LOW);
  pinMode(red,LOW);
  pinMode(green,LOW);
}

void loop() {
  if(digitalRead((ir1)==HIGH && a==true))  
  {
    a=false;
    b=true;
    c=true;
    Serial.println("ir1");
    digitalWrite(red,HIGH);
    digitalWrite(green,LOW);
    if(digitalRead((ir2)!=HIGH && (ir3)!=HIGH))
    {
      digitalWrite(buzzer,HIGH);
      delay(30);
      digitalWrite(buzzer,LOW);
      delay(30);
    }
  }
  if(digitalRead((ir2)==HIGH && b==true))
  {
    a=true;
    b=false;
    c=true;
    Serial.println("ir2");
    digitalWrite(red,HIGH);
    digitalWrite(green,LOW);
    int temp;
    temp=open_gate;
    while(temp>close_gate)
    {
      temp=temp-1;
      delay(160);
      myservo.write(temp);
    }
  }
  if(digitalRead((ir3)==HIGH && c==true))
  {
    a=true;
    b=true;
    c=false;
    Serial.println("ir3");
    digitalWrite(red,LOW);
    digitalWrite(green,HIGH);
    int temp;
    temp=close_gate;
    while(temp<open_gate)
    {
      temp=temp+1;
      delay(160);
      myservo.write(temp);
    }
  }
}
