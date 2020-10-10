// initialize keyboard library for instead of keyboard we using joystick
#include <Keyboard.h>   

//initialize the XY axis pin 
const int X_pin = A0; // analog pin connected to X output
const int Y_pin = A1; //  analog pin connected to Y output
int x, y;

void setup()
{
  Serial.begin(115200);
  Keyboard.begin();
}
void loop()
{
  x = analogRead(X_pin); // output of X_pin is read
  if (x == 1023) // check whether the value of x = 1023
  {
    Serial.println("Up:");
    Keyboard.press(218);
  }
  else
  {
    Keyboard.release(218);
  }
  
  x = analogRead(X_pin);  // output of X_pin is read
  if (x == 0) // check whether the value of x = 0

  {
    Serial.println("Down:");
    Keyboard.press(217);
    
  }
  else 
  {
    Keyboard.release(217);
  }


  y = analogRead(Y_pin);  // output of Y_pin is read
  if (y == 1023) // check whether the value of  y = 1023
  {
    Serial.println("Right:");
    Keyboard.write(217); // key moves right
  }
  else
  {
    Keyboard.release(217);
  }

 
  y = analogRead(Y_pin); // output of Y_pin is read
  if (y == 0) // check whether the value of y = 0
  {
    Serial.println("Left:");
    Keyboard.write(216); // key moves left
  }
  else 
  {
    Keyboard.release(216);
  }
  delay (200);
}
