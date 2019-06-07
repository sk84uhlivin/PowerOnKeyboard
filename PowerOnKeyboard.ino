#include <Keyboard.h>
const int led = 13;
const int buttonReset = 33; 
bool hasRan = false; //split key has not been pressed

void setup() {
  pinMode(led, OUTPUT); //sets up led for use
  pinMode(buttonReset, INPUT_PULLUP);
  Keyboard.begin(); //initialization of Keyboard function
}

void loop() {
  float bareMin = 3.0; //minimum voltage to activate 
  int sensorValue = analogRead(A4); //stores analog read to variable
  float voltage = sensorValue * (3.3 / 1023.0); //converts ADC value to voltage
  
  // if you press the button, you're allowed to use the program again
  if (digitalRead(buttonReset) == HIGH) {
    hasRan = false;   
  
} if (voltage > bareMin && !hasRan) {
    Keyboard.print("0"); //type split key of choice
    delay(5);
    hasRan = true; //split key has not been pressed, stop looking

} if (!hasRan) {
    digitalWrite(led, HIGH);
}   else {
      digitalWrite(led, LOW);
}
}

//to-do list
//add failsafe for hitting reset switch while power is on
