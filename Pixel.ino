#include <Adafruit_NeoPixel.h> // NeoPixel Library
#define D_PIN 0 
#define N_LED 8 
Adafruit_NeoPixel strip = Adafruit_NeoPixel(N_LED, D_PIN, NEO_GRB + 
NEO_KHZ800);
const int trigPin = 12;
const int echoPin = 13;
long duration;
int distance;
void setup() {
pinMode(trigPin, OUTPUT); // Sets the trigPin as an Output
pinMode(echoPin, INPUT); // Sets the echoPin as an Input
Serial.begin(115200); 
strip.begin();
strip.show(); 
}
void loop() {
digitalWrite(trigPin, LOW);
delayMicroseconds(2);
// Sets the trigPin on HIGH state for 10 micro seconds
digitalWrite(trigPin, HIGH);
delayMicroseconds(10);
digitalWrite(trigPin, LOW);
// Reads the echoPin, returns the sound wave travel time in microseconds
duration = pulseIn(echoPin, HIGH);
// Calculating the distance
distance= duration*0.034/2;
if(distance>=1000)
{
colorWipe(strip.Color(255, 255, 255), 1); 
// Prints the distance on the Serial Monitor
Serial.print(distance);
Serial.println("Go Ahead..");
37
}
else
{
colorWipe(strip.Color(255, 0, 255), 1); 
Serial.print(distance);
Serial.println("Stop");
delay(1000);
}
}
void colorWipe(uint32_t c, uint8_t wait) {
for(uint16_t i=0; i<strip.numPixels(); i++) {
strip.setPixelColor(i, c);
strip.show();
delay(wait)
}
