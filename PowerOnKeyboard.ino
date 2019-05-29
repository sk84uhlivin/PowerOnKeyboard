#include <Keyboard.h>
int led = 13;
int buttonReset = 32; 
bool skPress = false; //split key has not been pressed

void setup() {
  pinMode(led, OUTPUT); //sets up led for use
  pinMode(buttonReset,INPUT_PULLUP);
  Keyboard.begin(); //initialization of Keyboard function
}

void loop() {
  float bareMin = 3.0; //minimum voltage to activate 
  int sensorValue = analogRead(A4); //stores analog read to variable
  float voltage = sensorValue * (3.3 / 1023.0); //converts ADC value to voltage

  while (voltage > bareMin && skPress == false) {
    Keyboard.print("0"); //type split key of choice
    delay(5);0+
    digitalWrite(led, HIGH); // blink two times to confirm keystroke
    delay(250);
    digitalWrite(led, LOW);
    delay(250); 
    digitalWrite(led, HIGH);
    delay(250); 
    digitalWrite(led, LOW);
    delay(100);
    skPress = true; //split key has not been pressed, stop looking

  } 
}
