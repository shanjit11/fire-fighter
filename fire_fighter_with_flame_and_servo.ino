#include <Servo.h>
Servo myservo;
int pin8 = 8; // buzzer
int pin7 = 7; // relais pompe à eau
int sensorflamme = A1;
int sensorValue1 = 0;
void setup() { 
myservo.attach(9);  // SERVO SUR pin D9 
pinMode(pin8, OUTPUT);
pinMode(pin7, OUTPUT);
Serial.begin(9600);
digitalWrite(pin8, LOW);
digitalWrite(pin7, LOW);
myservo.write(170);
}
void loop() {
myservo.write(15);  
delay (1000);
for ( int balayage = 15 ; balayage <= 150; balayage = balayage + 1 
)
{
myservo.write(balayage);  
sensorValue1 = analogRead(sensorflamme);
Serial.println(sensorValue1);
delay (20);
if (sensorValue1 < 850) {
digitalWrite(pin8, HIGH); // active buzzer
digitalWrite(pin7, HIGH); // allumage pompe
for ( int repetition = 0 ; repetition <=5 ; repetition = repetition + 1 
)
{
for ( int incendie = balayage - 18 ; incendie <= balayage + 15 ; 
incendie = incendie + 1 )
{
myservo.write(incendie);  
delay (20);
}
}
digitalWrite(pin7, LOW);
}
else {
digitalWrite(pin8, LOW);
digitalWrite(pin7, LOW);
}
}
}
