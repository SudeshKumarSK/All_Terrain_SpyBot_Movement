int lm1=2,lm2=3,rm1=4,rm2=5,led=7;
void Forward()
{
  digitalWrite(lm1,1);
  digitalWrite(lm2,0);
  digitalWrite(rm1,1);
  digitalWrite(rm2,0);
}


void Stop()
{
  digitalWrite(lm1,0);
  digitalWrite(lm2,0);
  digitalWrite(rm1,0);
  digitalWrite(rm2,0);
}


void Reverse()
{
  digitalWrite(lm1,0);
  digitalWrite(lm2,1);
  digitalWrite(rm1,0);
  digitalWrite(rm2,1);
}


void Right()
{
  digitalWrite(lm1,1);
  digitalWrite(lm2,0);
  digitalWrite(rm1,0);
  digitalWrite(rm2,1);
}

void Left()
{
  digitalWrite(lm1,0);
  digitalWrite(lm2,1);
  digitalWrite(rm1,1);
  digitalWrite(rm2,0);
}

const int chA=22;  //Constant variables relating to pin locations
int ch1;  
const int chB=23;  //Constant variables relating to pin locations
int ch2;
const int chC=25;  //Constant variables relating to pin locations
int ch3;//Varibles to store and display the values of each channel
                                                   
// the setup routine runs once when you press reset:
void setup() {
  // initialize serial communication at 9600 bits per second:
  Serial.begin(115200);
  // Set input pins
  pinMode(chA, INPUT);
  pinMode(chB, INPUT);
  pinMode(chC, INPUT);
  pinMode(lm1,OUTPUT);
  pinMode(lm2,OUTPUT);
  pinMode(rm1,OUTPUT);
  pinMode(rm2,OUTPUT);
  pinMode(led,OUTPUT);
}

//Main Program
void loop() {
  // read the input channels
  ch1 = pulseIn (chA,HIGH);
 Serial.println("");
 Serial.print ("Ch1:");
 Serial.print (ch1);
 Serial.print (" | ");//Print in the value of channel 1
  
  ch2 = pulseIn (chB,HIGH);
  Serial.print("");
 Serial.print ("Ch2:");
 Serial.print (ch2);
 Serial.print (" | ");//Print in the value of channel 1
 
  ch3 = pulseIn (chC,HIGH);
  Serial.print("");
 Serial.print ("Ch3:");
 Serial.print (ch3);
 Serial.print (" | ");//Print in the value of channel 1
 
  //fwd

 if((ch1>1300&&ch1<1700)&&(ch2<1700&&ch2>1300))
 {
  Stop();
  
 }
  else if(ch1<1300)
  {
    Right();
  }

  //right
  else if(ch1>1700)
  {
    Left();
   }
  //left 
  else if(ch2>1700)
  {
    Forward();

  }

  else if(ch2<1300)
  {
    Reverse();
  }
  if(ch3<1200)
  {
    Serial.write("low");
    digitalWrite(led,1);
  }
  else if(ch3>1200)
  {
    Serial.write("high");
    digitalWrite(led,0);
  }
}  
  


