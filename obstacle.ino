#define LeftLeg 2 
#define RightLeg 3
#define LeftFoot 4 
#define RightFoot 5 
int Buzzer = 13;
#define trigPin 8
#define echoPin 9
#include <Otto.h>
Otto Otto;  //This is Otto
String direction;
void setup() {
  Serial.begin(9600);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);

  Otto.init(LeftLeg, RightLeg, LeftFoot, RightFoot, true,Buzzer); //Set the servo pins and Buzzer pin
}
void loop() {
  // Read the distance from the ultrasonic sensor
  long duration, distance;
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distance = duration / 58.2;
  
 if (distance > 10) {
    // Forward movement
    Forward();
  } else {
    // Right movement
    Right();
  }

  // Print the distance to the serial monitor
  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");

  // Delay for 100 milliseconds
  delay(100);
}


void Forward() {
  Otto.walk(5,1000,1);
 
}

void Backward() {
  Otto.walk(5,1000,-1);
}

void Right(){
  for (int i = 0; i < 5; i++) {
  Otto.turn(1,1000,-1);
  }
}

void Left(){
  Otto.turn(3,1000,1);
}

void Stop(){
  Otto.walk(0,1000,1);
  Otto.turn(0,1000,1);
  Otto.walk(0,1000,-1);
  Otto.turn(0,1000,-1);
}
