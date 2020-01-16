#include "Servo.h"

const int debug = 0;

const int redPotPin = 0;
const int bluePotPin = 1;
const int yellowPotPin = 3;
const int whitePotPin = 4;

const int talon1pin = 11;
const int talon2pin = 10;
const int talon3pin = 9;
const int talon4pin = 6;

Servo talon1;
Servo talon2;
Servo talon3;
Servo talon4;

void setup() {
  // put your setup code here, to run once:
 if (debug) {
    Serial.begin(9600);
    Serial.print("setup\n");
  }
 // set up motors pwm pins
  talon1.attach(talon1pin);
  talon2.attach(talon2pin);
  talon3.attach(talon3pin);
  talon4.attach(talon4pin);
}

int pwmFromPot(int pin){
  int val = analogRead(pin);
  int pwm = map(val, 0, 1024, 0, 180);
  if (debug){
    Serial.print("pin = ");
    Serial.print(pin);
    Serial.print(" val = ");
    Serial.print(val);
    Serial.print(" pwm = ");
    Serial.print(pwm);
    Serial.print("\n");
  }
  return pwm;
}

void loop() {
  // put your main code here, to run repeatedly:
  talon1.write(pwmFromPot(redPotPin));
  talon2.write(pwmFromPot(bluePotPin));
  talon3.write(pwmFromPot(yellowPotPin));
  talon4.write(pwmFromPot(whitePotPin));
  // delay(15);
}
