/*
  Hız sınırı 4500 olsun.
    Pot değeri 1Kohm.
  Pot 100 değerindeyken motor hızı 2100rpm'dir. Motor 
  hızı buna göre hesaplanmıştır. +-300,400 hata payı olabilir.

*/

#define led 7
#define motor 10
void setup()
{
  pinMode(led, OUTPUT);   
  pinMode(motor, OUTPUT);//PWM Pin 
  Serial.begin(9600);
}

void loop()
{
  int pot=analogRead(A5);
  pot=map(pot,0,1023,0,255);
  
  Serial.print("Pot Degeri: ");
  Serial.println(pot);
  analogWrite(motor,pot);
  int motorHizi=map(pot,0,255,0,6666);
  if(motorHizi>=4500){ digitalWrite(led,1); }
  else{ digitalWrite(led,0); }
  Serial.print("Motor Hizi: ");
  Serial.println(motorHizi);
}
