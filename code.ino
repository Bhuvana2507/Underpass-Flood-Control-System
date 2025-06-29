#include <Servo.h>
#define sensorPower 10
#define sensorPin A0

// Value for storing water level
int val = 0;

int rled=3;
int led=4;
int m1=6;
int m2=7;
Servo myservo;  // create servo object to control a servo
// twelve servo objects can be created on most boards

int pos = 0;    // variable to store the servo position
void opn(){
 for (pos = 0; pos <= 160; pos += 1) { // goes from 0 degrees to 180 degrees
    // in steps of 1 degree
    myservo.write(pos);              // tell servo to go to position in variable 'pos'
    delay(15);                       // waits 15 ms for the servo to reach the position
  }
}
void clse(){
  for (pos = 160; pos >= 0; pos -= 1) { // goes from 180 degrees to 0 degrees
    myservo.write(pos);              // tell servo to go to position in variable 'pos'
    delay(15);                       // waits 15 ms for the servo to reach the position
  }
  }
void setup() {
pinMode(m1,OUTPUT);
pinMode(m2,OUTPUT);
pinMode(rled,OUTPUT);
pinMode(led,OUTPUT);  // put your setup code here, to run once:
pinMode(sensorPower, OUTPUT);
	
	// Set to LOW so no power flows through the sensor
	digitalWrite(sensorPower, LOW);
Serial.begin(9600);
myservo.attach(5);


}
int wl=0;
int gs=0;
void loop() {
int wl = analogRead(A0);
	
	Serial.print("Water level: ");
	Serial.println(wl);
	
	delay(1000);

if(wl<550){
digitalWrite(rled,1);
digitalWrite(led,0);
digitalWrite(m1,1);
digitalWrite(m2,0);
if(gs==0){
gs=1;
opn();
}
}
if(wl>950){
digitalWrite(rled,0);
digitalWrite(led,1);
digitalWrite(m1,0);
digitalWrite(m2,0);
if(gs==1){
gs=0;
clse();
}
}
}
int readSensor() {
	digitalWrite(sensorPower, HIGH);	// Turn the sensor ON
	delay(10);							// wait 10 milliseconds
	val = analogRead(sensorPin);		// Read the analog value form sensor
	digitalWrite(sensorPower, LOW);		// Turn the sensor OFF
	return val;							// send current reading
}
