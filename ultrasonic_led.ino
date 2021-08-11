// define pins
const int trigPin = 9; 
const int echoPin = 10;

// define variables
long duration;
int distance;
int cm;


void setup(){
   pinMode(trigPin,OUTPUT);
   pinMode(echoPin,INPUT);
   Serial.begin(9600); 
}



void loop() {
    // The sensor is triggered by a HIGH pulse of 10 or more microseconds.
    // Give a short LOW pulse beforehand to ensure a clean HIGH pulse:
    digitalWrite(trigPin, LOW);
    delayMicroseconds(2); 
    digitalWrite(trigPin, HIGH);
    delayMicroseconds(10);
    digitalWrite(trigPin, LOW);   

    // Read the signal from the sensor: a HIGH pulse whose
    // duration is the time (in microseconds) from the sending
    // of the ping to the reception of its echo off of an object.
    duration = pulseIn(echoPin, HIGH);    
    
    // Convert the time into a distance
    distance= duration*0.034/2;
 
    Serial.print("Distance: ");
    Serial.println(distance);
  cm = distance;
    cm = map(cm,1,1178,255,1);
        analogWrite(11,cm);
}
