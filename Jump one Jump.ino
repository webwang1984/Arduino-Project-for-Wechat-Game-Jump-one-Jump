#include <Servo.h>
 
Servo myservo;
 
int char_to_int(char i)
{
  switch(i)
  {
  case '0':return 0;
  case '1':return 1;
  case '2':return 2;
  case '3':return 3;
  case '4':return 4;
  case '5':return 5;
  case '6':return 6;
  case '7':return 7;
  case '8':return 8;
  case '9':return 9;
  default: return 0;
  }
}
 
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(8,OUTPUT);
  myservo.attach(8);
  myservo.write(120);
  delay(2000);
}
 
void loop() {
  // put your main code here, to run repeatedly:
  char a,b,c;
  int i;
  while(!Serial.available());//等待数据
  if(Serial.available())
  {
    a=Serial.read();
    delay(3);
  }
  if(Serial.available())
  {
    b=Serial.read();
    delay(3);
  }
  if(Serial.available())
  {
    c=Serial.read();
    delay(3);
  }
  if(b==0)
  {
    i=char_to_int(a);
    Serial.println(i,DEC);
  }
   
  else if(c==0)
  {
    i=char_to_int(a)*10+char_to_int(b);
    Serial.println(i,DEC);
  }
  else
  {
    i=char_to_int(a)*100+char_to_int(b)*10+char_to_int(c);
    Serial.println(i,DEC);
  }
  i=i*23;
  for(int j=120;j<=137;j++)
  {
    myservo.write(j);
    delay(5);
  }
  delay(i);
  for(int j=137;j>=120;j--)
  {
    myservo.write(j);
    delay(5);
  }
}
