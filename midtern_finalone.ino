#define pinTrig 13
#define pinEcho 12
byte pinColorR=A0;
byte pinColorG=A1;
byte pinColorB=A2;
int valueR;
int valueG;
int valueB;
byte pinLed_a[]={3,5,6};
byte pinLed_b[]={9,10,11};
long dura,cm;
void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
pinMode(pinTrig,OUTPUT);
pinMode(pinEcho,INPUT);
digitalWrite(pinTrig,LOW);
for(int i=0;i<3;i++)
  {
  pinMode(pinLed_a[i],OUTPUT);
    pinMode(pinLed_b[i],OUTPUT);
  }

}
void loop() {
  // put your main code here, to run repeatedly:
digitalWrite(pinTrig,HIGH);
delayMicroseconds(10);
digitalWrite(pinTrig,LOW);

dura=pulseIn(pinEcho,HIGH);
cm=dura/58;
Serial.print(cm);
Serial.println();
valueR=analogRead(pinColorR);
  valueG=analogRead(pinColorG);
  valueB=analogRead(pinColorB);
  valueR/=4;
  valueG/=4;
  valueB/=4;
  if(cm<5)
  {
     analogWrite(pinLed_a[0],valueR+50);
  analogWrite(pinLed_a[1],valueG-50);
  analogWrite(pinLed_a[2],valueB+50);
  analogWrite(pinLed_b[0],valueG-50);
  analogWrite(pinLed_b[1],valueB+50);
  analogWrite(pinLed_b[2],valueR-50);
  }
  else if(cm>4&&cm<10)
  {
    analogWrite(pinLed_a[0],valueR-50);
  analogWrite(pinLed_a[1],valueG+50);
  analogWrite(pinLed_a[2],valueB-50);
  analogWrite(pinLed_b[0],valueG+50);
  analogWrite(pinLed_b[1],valueB-50);
  analogWrite(pinLed_b[2],valueR+50);
  }
  else if(cm>9)
  {
     analogWrite(pinLed_a[0],valueR);
  analogWrite(pinLed_a[1],valueG);
  analogWrite(pinLed_a[2],valueB);
  analogWrite(pinLed_b[0],valueG);
  analogWrite(pinLed_b[1],valueB);
  analogWrite(pinLed_b[2],valueR);
  }
}
