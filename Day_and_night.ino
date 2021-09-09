#define LDR1_anal A0
const int LDR_Minimum=500;
int led = 13;
int trigpin = 9;
int echopin = 10;
bool LDR1 = LOW;
bool LDR2 = LOW;
long duration;
int distance;
int safetyDistance;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(led, OUTPUT);
  pinMode(trigpin, OUTPUT);
  pinMode(echopin, INPUT);
}

void loop() {
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
}
