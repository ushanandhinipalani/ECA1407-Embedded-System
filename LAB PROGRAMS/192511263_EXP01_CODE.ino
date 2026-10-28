//NAME:USHA NANDHINI P
//REGNO:192511263
//CLASS:ECE
//ECA1407-EMBEDDED SYSTEM
#define GAS_PIN A0
#define PIR_PIN 2
#define TRIG_PIN 8
#define ECHO_PIN 9
#define BUZZER 10
#define LED 11
void setup()
{
Serial.begin(9600);
pinMode(PIR_PIN, INPUT);
pinMode(TRIG_PIN, OUTPUT);
pinMode(ECHO_PIN, INPUT);
pinMode(BUZZER, OUTPUT);
pinMode(LED, OUTPUT);
}
void loop()
{
int gas = analogRead(GAS_PIN);
int motion = digitalRead(PIR_PIN);
digitalWrite(TRIG_PIN, LOW);
delayMicroseconds(2);
digitalWrite(TRIG_PIN, HIGH);
delayMicroseconds(10);
digitalWrite(TRIG_PIN, LOW);
long duration = pulseIn(ECHO_PIN, HIGH);
float distance = duration * 0.0343 / 2;
if (gas > 500)
digitalWrite(BUZZER, HIGH);
else
digitalWrite(BUZZER, LOW);

digitalWrite(LED, motion);
Serial.print("Gas Level: ");
Serial.println(gas);
Serial.print("Motion: ");
if (motion)
Serial.println("DETECTED");
else
Serial.println("NOT DETECTED");
Serial.print("Distance: ");
Serial.print(distance, 1);
Serial.println(" cm");
if (gas > 500)
Serial.println("GAS ALERT!");
else if (motion)
Serial.println("OCCUPANCY DETECTED");
else
Serial.println("SYSTEM SAFE");
Serial.println("--------------------");
delay(1000);
}
