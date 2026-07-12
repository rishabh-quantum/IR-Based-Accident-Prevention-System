// Accident Preven on System for Crossroads 
// Using Arduino Nano, 2 IR sensors, 4 LEDs, and a buzzer

int ir1 = 2;  // IR Sensor 1 (Road 1) 
int ir2 = 3;  // IR Sensor 2 (Road 2) 
int red1 = 4;  // Road 1 Red LED 
int green1 = 5;  // Road 1 Green LED 
int red2 = 6;  // Road 2 Red LED 
int green2 = 7;  // Road 2 Green LED 
int buzzer = 8;  // Buzzer 
void setup() 
{ 
} 
pinMode(ir1, INPUT); 
pinMode(ir2, INPUT); 
pinMode(red1, OUTPUT); 
pinMode(green1, OUTPUT); 
pinMode(red2, OUTPUT); 
pinMode(green2, OUTPUT); 
pinMode(buzzer, OUTPUT); 
// Ini alize all OFF 
digitalWrite(red1, LOW); 
digitalWrite(green1, LOW); 
digitalWrite(red2, LOW); 
digitalWrite(green2, LOW); 
digitalWrite(buzzer, LOW); 
void loop()  
{ 
int s1 = digitalRead(ir1);  // Read IR1 state
int s2 = digitalRead(ir2);  // Read IR2 state 
 
  // IR sensors usually give LOW when an object (car) is detected 
  bool car1 = (s1 == LOW); 
  bool car2 = (s2 == LOW); 
 
  // CASE 1: Cars on both roads → possible accident 
  if (car1 && car2)  
{ 
    digitalWrite(red1, HIGH); 
    digitalWrite(green1, LOW); 
    digitalWrite(red2, HIGH); 
    digitalWrite(green2, LOW); 
    digitalWrite(buzzer, HIGH);   // Sound alarm 
  } 
 
  // CASE 2: Car only on Road 1 
  else if (car1 && !car2)  
{ 
    digitalWrite(green1, HIGH);   // Road 1 GO 
    digitalWrite(red1, LOW); 
    digitalWrite(red2, HIGH);     // Road 2 STOP 
    digitalWrite(green2, LOW); 
    digitalWrite(buzzer, LOW); 
  } 
 
  // CASE 3: Car only on Road 2 
  else if (car1 && car2)  
{
digitalWrite(red1, HIGH);     // Road 1 STOP 
    digitalWrite(green1, LOW); 
    digitalWrite(green2, HIGH);   // Road 2 GO 
    digitalWrite(red2, LOW); 
    digitalWrite(buzzer, LOW); 
  } 
 
  // CASE 4: No car detected → both GREEN 
  Else 
 { 
    digitalWrite(red1, LOW); 
    digitalWrite(green1, HIGH); 
    digitalWrite(red2, LOW); 
    digitalWrite(green2, HIGH); 
    digitalWrite(buzzer, LOW); 
  } 
 
  delay(200);  // small delay for stable readings 
}
