// Obstacle avoidance code
//Obstacle detected: Stop; left; stop; forward; stop; right; stop; forward; 

int IR = 6;
int s1=2;
int s2=3;
int s3=4;
int s4=5;

void setup() {
  // put your setup code here, to run once:
  pinMode(s1,OUTPUT);
  pinMode(s2,OUTPUT);
  pinMode(s3,OUTPUT);
  pinMode(s4,OUTPUT);
  pinMode(IR,INPUT);
  Serial.begin(9600);
  
}

void forward()
{ 
  //Control();
  digitalWrite(s1,1);
  digitalWrite(s2,0);
  digitalWrite(s3,1);
  digitalWrite(s4,0);
  Serial.println("Forward Direction");
}

void right()
{
  digitalWrite(s1,0);
  digitalWrite(s2,0);
  digitalWrite(s3,1);
  digitalWrite(s4,0);
  Serial.println("Right Direction");
}


void left()
{
  digitalWrite(s1,1);
  digitalWrite(s2,0);
  digitalWrite(s3,0);
  digitalWrite(s4,0);
  Serial.println("Left Direction");
}

void Stop()
{
  digitalWrite(s1,0);
  digitalWrite(s2,0);
  digitalWrite(s3,0);
  digitalWrite(s4,0);
  Serial.println("Stop");
}


void loop() {
  // put your main code here, to run repeatedly:
  int ir = digitalRead(IR);
  
  if(ir == 1)
  {
    tone (15,1000,1000);
    
    Stop();
    delay(1000);
    left();
    delay(2000);
    Stop();
    delay(1000);
    forward();
    delay(3000);
    Stop();
    delay(1000);
    right();
    delay(1000);
    Stop();
    delay(1000);
    forward();
    delay(5000);
    Stop();
  }

  else{
    forward();
  }

}
