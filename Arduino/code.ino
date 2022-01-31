// Includes the Servo library
#include <Servo.h>
const int trigPin = 10;
const int echoPin = 11;
const int buzzer = 9;
const int ledPin = 13;
// Variables for the duration and the distance
long duration;
int distance;
//int safetyDistance;
Servo myServo;	// Creates a servo object for controlling the servo motor
void setup() {
    pinMode(trigPin, OUTPUT); 	// Sets the trigPin as an Output
    pinMode(echoPin, INPUT);	// Sets the echoPin as an Input
    pinMode(buzzer, OUTPUT);
    pinMode(ledPin, OUTPUT);
    Serial.begin(9600);
    myServo.attach(12);		// Defines on which pin is the servo motor attached
}
void loop() {
    for(int i=60;i<=120;i++){	// rotates the servo motor from 60 to 120 degrees
        myServo.write(i);
        delay(30);
        distance = calculateDistance();	// Calls a function for calculating the distance measured by the Ultrasonic sensor for each degree
        Serial.print(i); // Sends the current degree into the Serial Port
		Serial.print(","); // Sends addition character right next to the previous value needed later in the Processing IDE for indexing
		Serial.print(distance); // Sends the distance value into the Serial Port
		Serial.print("."); // Sends addition character right next to the previous value needed later in the Processing IDE for indexing
    }
    
    for(int i=120;i>60;i--){
        myServo.write(i);
        delay(30);
        distance = calculateDistance();
        Serial.print(i);
        Serial.print(",");
        Serial.print(distance);
        Serial.print(".");
    }
}
// Function for calculating the distance measured by the Ultrasonic sensor
int calculateDistance(){
    digitalWrite(trigPin, LOW);
    delayMicroseconds(2);
  
    digitalWrite(trigPin, HIGH);
    delayMicroseconds(10);
	// Sets the trigPin on HIGH state for 10 micro seconds
    digitalWrite(trigPin, LOW);
    duration = pulseIn(echoPin, HIGH);	// Reads the echoPin, returns the sound wave travel time in microseconds
    distance= duration*0.034/2;
    if (distance <= 20){
  digitalWrite(buzzer, HIGH);
  digitalWrite(ledPin, HIGH);
}
else{
  digitalWrite(buzzer, LOW);
  digitalWrite(ledPin, LOW);
} 
    return distance;
}



    
