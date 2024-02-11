#include <Stepper.h> 
#define STEPS 2038 // the number of steps in one revolution of your motor (28BYJ-48)
const int stepsPerRevolution = 2038;
const int trigPin = 5;
const int echoPin = 6;

long duration;
int distance;
int roundAngle;
int Angle;
Stepper stepper(STEPS, 8, 10, 9, 11);
// 1-3-2-4

int stepCount = 0;

void setup() {
// nothing to do
 pinMode(trigPin, OUTPUT);
 pinMode(echoPin, INPUT);
 Serial.begin(9600);
}

void loop() {
  stepper.setSpeed(4);
  stepper.step(5);
  distance = calculateDistance();
  delay(0);
  Angle = stepCount*0.883218842;
  roundAngle = (int)Angle;
  Serial.print(Angle);
  Serial.print(",");
  Serial.print(distance);
  Serial.print(".");
  stepCount++;
  if (stepCount==408) {stepCount =0;}

  
}
  int calculateDistance(){

    digitalWrite(trigPin, LOW);
    delayMicroseconds(2);
    digitalWrite(trigPin, HIGH);
    delayMicroseconds(10);
    digitalWrite(trigPin, LOW);
    duration = pulseIn(echoPin, HIGH);
    distance = duration*0.034/2;
    
    return distance;
  }
