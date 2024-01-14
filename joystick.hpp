#include "mbed.h"

enum JoystickDirection { LeftTrigg, RightTrigg, NoTrigg };

class Joystick {
public:
  Joystick(PinName xPin, PinName yPin);

  void calibrate();

  float getX();
  float getY();

  JoystickDirection Ytriggered();
  float Xtriggered();

private:
  AnalogIn xInput;
  AnalogIn yInput;

  float minX;
  float maxX;
  float minY;
  float maxY;

  const float yTriggLimit = 0.95;
  const float xTriggLimit = 0.70;
};
