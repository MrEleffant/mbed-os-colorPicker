#include "mbed.h"
#include <iostream>

#include "color.hpp"
#include "joystick.hpp"


const PinName joystickXPin = A0;
const PinName joystickYPin = A1;

int main() {
  Joystick joystick(joystickXPin, joystickYPin);
  joystick.calibrate();

  color guessColor;

  while (true) {
    if (joystick.Ytriggered() == JoystickDirection::LeftTrigg) {
      std::cout << "Selecting prev color : " << guessColor.previousColor() << std::endl;
    } else if (joystick.Ytriggered() == JoystickDirection::RightTrigg) {
      std::cout << "Selecting next color : " << guessColor.nextColor() <<std::endl;
    }


    float coeff = joystick.Xtriggered();
    if(coeff != 0.0) {
      guessColor.moveColor(coeff);
    }a







    ThisThread::sleep_for(100ms);
  }
}
