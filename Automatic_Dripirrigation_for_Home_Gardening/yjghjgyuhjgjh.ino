#define RELAY_PIN 2
const int sensor_pin = A1;	

void setup() {
  pinMode(RELAY_PIN,OUTPUT);
  Serial.begin(9600);	
}

void loop() {
  float moisture_percentage;
  int sensor_analog;
  sensor_analog = analogRead(sensor_pin);
  moisture_percentage = ( 100 - ( (sensor_analog/1023.00) * 100 ) );
  Serial.print("Moisture Percentage = ");
  Serial.print(moisture_percentage);
  Serial.print("%\n\n");
  delay(1000);

if (moisture_percentage>20)
{
digitalWrite(RELAY_PIN,LOW);

}
else{
digitalWrite(RELAY_PIN,HIGH);
}
}