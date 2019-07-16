# PowerOnKeyboard

### Introduction

PowerOnKeyboard is an Arduino based device designed to automatically start splits when powering on a video game console. It does this based on the detection of voltage from the controller of the console. It currently uses a ATmega32u4 to have the Arduino act as an HID, but will eventually move to a serial protocol in the future. Until then, this means you must use a ATmega32u4 or Cortex based Arduino that is 5V tolerant. Common ones include Leonardo, Micro, and Teensy 3.2 and 3.6. These three will all accomplish the job equally without porting or adjustments, so pick whichever one fits your needs best. I recommend the Leonardo for simplicity (pre-installed headers, common), or a Teensy 3.2 for a small footprint. Using 5V game controllers on a 3.3V Arduino can result in damage to any and all of your components in the circuit. ***Please be careful.***

Otherwise, the list of mandatory materials:

 1. 32u4/Cortex based Arduino
 2. Appropriate USB cable
 3. Momentary Switch, SPST, Normally Off
 4. Controller extension cable for your console of choice
 5. Soldering iron
 6. Wire Strippers
 7. (Dupont) Wires

### Circuit Setup

Starting by cutting your extension cable in half, exposing all the signal lines, and soldering them back together. Then, solder one end of a wire to the power line, and connect the other end to port "A1" on the Arduino. Then connect one terminal of your momentary switch to digital pin 2 on the Arduino, and the other end to GND on the Arduino. Using a [Fritzing](https://fritzing.org/home/) breadboard model, it should look something like this if you're using an Arduino Micro (ignoring the obsolete controller signals):

![Arduino Micro Example](https://raw.githubusercontent.com/sk84uhlivin/PowerOnKeyboard/master/fritzingmodel.PNG)

### Firmware

With the circuit complete, let's look at the firmware. You'll notice two constants at the top called "splitKey" and "resetKey". These are the keystrokes that will be typed when you power on your console, and reset your splits respectively. Assign these to your choosing, and upload the firmware to the Arduino.

### Operation

Upon uploading firmware to, or powering on the Arduino, it will be ready to send a splitKey on power on. Therefore do not start the program with the console powered on, or it will send a splitKey press. You will also notice the built-in LED on your Arduino will be lit. When this LED is on, the program is ready to send a splitKey. Otherwise, when you turn on your console, a splitKey will be sent. To reset your splits, simply hit the reset button in the circuit. Once a splitKey has been sent, it will *never* send another splitKey press again until these two criteria are met, in any order:

 - The reset button has been pressed
 - There is no power present from the controller

When both these conditions are met, the LED will turn back on and you may send a splitKey again. This is not only so you can reset with the power on, but also to prevent games that turn the power to the controller on and off during gameplay. 

