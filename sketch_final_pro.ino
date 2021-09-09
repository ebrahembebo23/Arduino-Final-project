#define LDR1_anal A0
#include <Servo.h>
const int LDR_Minimum=500;
int led = 13;
int trigpin = 9;
int echopin = 10;
bool LDR1 = LOW;
bool LDR2 = LOW;
long duration;
int distance;
int safetyDistance;
int servopin = 6;
int servoposition = 180;
const int buzzer = 3;
Servo myservo;

void setup() {
  // put your setup code here, to run once:
  pinMode(buzzer, OUTPUT);
  myservo.attach(servopin);
  Serial.begin(9600);
  pinMode(led, OUTPUT);
  pinMode(trigpin, OUTPUT);
  pinMode(echopin, INPUT);
}

void loop() {
tone(buzzer, 1000);
  delay(1000);        
  noTone(buzzer); 
  delay(1000);
  if(analogRead(LDR1_anal)>LDR_Minimum   && LDR1==LOW )
  {
    LDR1 = HIGH;
  }
  if (LDR1 == HIGH)
  {
      Serial.println("DAY");
  }
  else
  {
  Serial.println("NIGHT");
  }
  // Clears the trigPin
digitalWrite(trigpin, LOW);
delayMicroseconds(2);

// Sets the trigPin on HIGH state for 10 micro seconds
digitalWrite(trigpin, HIGH);
delayMicroseconds(10);
digitalWrite(trigpin, LOW);
  // Reads the echoPin, returns the sound wave travel time in microseconds
duration = pulseIn(echopin, HIGH);

// Calculating the distance
distance= duration*0.034/2;

safetyDistance = distance;
if (safetyDistance <= 5){
  digitalWrite(led, HIGH);
}
else{
  
  digitalWrite(led, LOW);
}
// Prints the distance on the Serial Monitor
Serial.print("Distance: ");
Serial.println(distance);

myservo.detach();
    delay(1000);
    myservo.attach(servopin);
    myservo.write(servoposition);
    delay(1000);
    myservo.detach();
    
    myservo.attach(servopin);
    myservo.write(0);
    delay(1000);

    


   

}
