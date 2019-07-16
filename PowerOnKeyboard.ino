#include <Keyboard.h>
const int resetButton = 2; //Reset button on pin 2.
const byte volCon = A1; //Controller voltage on pin A1.
bool hasReset = false;
bool hasPermission = true;

const byte splitKey = 0;
const byte resetKey = 9;

void setup() {
  pinMode(LED_BUILTIN, OUTPUT); //Sets up built-in Arduino LED for use.
  pinMode(resetButton, INPUT_PULLUP); //Sets up button for use w/ pullup resistor.
  Keyboard.begin(); //Initialization of Keyboard function.
}

void loop() {
  float bareMin = 3.0; //Minimum voltage to activate Power On. 
  int sensorValue = analogRead(volCon); //Reads voltage from A1 and stores integer to a variable.
  float voltage = sensorValue * (3.3 / 1023.0); //Converts ADC value to voltage.
  
  // Reset Key - Resets Power On function and activates Reset hotkey.
  if (digitalRead(resetButton) == HIGH & hasReset) { //If the button is pressed...
    Keyboard.print(splitKey); //...type reset key of choice.
    delay(15);
    hasReset = false; //Split key can be used again.
    
  // Permission to run on Power On
} if (voltage < bareMin && !hasReset) { //If no voltage is present and reset key has been pushed...
    hasPermission = true; //Power on may be used.
    delay(50);

  // Power On
} if (voltage > bareMin && hasPermission) {  //If voltage goes above 3V and reset key hasn't been pushed...
    Keyboard.print(resetKey); //...type split key of choice
    delay(15);
    hasReset = true; //Split key has been pressed.
    hasPermission = false; //Permission revoked.

  // LED Indicator
} if (hasPermission) { //If you have permission to use Power On...
    digitalWrite(LED_BUILTIN, HIGH); //Power on the LED. Otherwise...
}   else {
      digitalWrite(LED_BUILTIN, LOW); } //Turn the LED off. 
}
