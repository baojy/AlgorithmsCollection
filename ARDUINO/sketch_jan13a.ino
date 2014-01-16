//SmartAutoRunCarV1.0.0.1(Bata)
  int pinleft=11;
  int pinright=10;
  int pinsigleft=8;
  int pinsigright=9;
  int pintrig=13;
  int pinecho=12;
  //int dist = 10000;//
  int dir = 0;
  int left=1;
  int right=1;
  int flag=0;

void setup()
{
  Serial.begin(9600);
  pinMode(pinleft,OUTPUT);
  pinMode(pinright,OUTPUT);
  pinMode(pinsigleft,INPUT);
  pinMode(pinsigright,INPUT);
  pinMode(pintrig,OUTPUT);
  pinMode(pinecho,INPUT);
}

void loop()
{
  //ReadDist_Dirsig
  long duration,distance;
  digitalWrite(pintrig,LOW);
  delayMicroseconds(2);
  digitalWrite(pintrig,HIGH);
  delayMicroseconds(10);
  digitalWrite(pintrig,LOW);
  duration=pulseIn(pinecho,HIGH);
  distance=(duration/2)/29.1;
  
  //ReadDir
  left=digitalRead(pinsigleft);
  right=digitalRead(pinsigright);
  if(right==0&&left==0)
    {
      //stop
    flag=1;
    //digitalWrite(pinleft,LOW);
    //digitalWrite(pinright,LOW);
    }
  if(right==1&&left==0)
  {
      //tunright
      dir=1;
      flag=0;
  }
  if(right==0&&left==1)
  {
      //tunleft
      dir=2;
      flag=0;
  }
  if(right==1&&left==1)
  {
      //goahead
      dir=0; 
      flag=0;
  }
  
//Run&&no  
  if(distance<=8||flag==1)
  {
    digitalWrite(pinleft,LOW);
    digitalWrite(pinright,LOW);
  }
  else if(dir==0&&flag==0)
  {
    digitalWrite(pinleft,HIGH);
    digitalWrite(pinright,HIGH);
  }
  else if(dir==1&&flag==0)
  {
    digitalWrite(pinleft,HIGH);
    digitalWrite(pinright,LOW);
  }
  else if(dir==2&&flag==0)
  {
    digitalWrite(pinleft,LOW);
    digitalWrite(pinright,HIGH);
  }
  delay(1);
}
