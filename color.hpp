//
// Created by thiba on 29/11/2023.
//

#ifndef CPP_FCT_COLOR_HPP
#define CPP_FCT_COLOR_HPP

#include <iostream>

enum colors { red, green, blue };

class color {
private:
  int red = 255;
  int green = 255;
  int blue = 255;

  colors selectedColor = colors::red;
  static const int NUM_COLORS = 3;

public:
  virtual ~color(){};

public: // setter
  void set_r(int r) { this->red = r; }
  void set_g(int g) { this->green = g; }
  void set_b(int b) { this->blue = b; }

public: // getter
  int get_r() { return this->red; }
  int get_g() { return this->green; }
  int get_b() { return this->blue; }

private:
  unsigned long INT_TO_HEX_RGB(int r, int g, int b, int alpha);
  int RND_INT_FOR_COLOR();
  const char *colorToString(colors color);

public:
  void gen_rnd_color() {
    this->red = RND_INT_FOR_COLOR();
    this->green = RND_INT_FOR_COLOR();
    this->blue = RND_INT_FOR_COLOR();
    return;
  }

  unsigned long get_HEX_CODE() {
    return INT_TO_HEX_RGB(this->red, this->green, this->blue, 255);
  }

private:
int constrainValue(int value, int min, int max) {
    if (value < min) {
        return min;
    } else if (value > max) {
        return max;
    } else {
        return value;
    }
}

public:
  const char *nextColor() {
    this->selectedColor =
        static_cast<colors>((this->selectedColor + 1) % NUM_COLORS);
    return colorToString(this->selectedColor);
  }
  const char *previousColor() {
    this->selectedColor = static_cast<colors>(
        (this->selectedColor - 1 + NUM_COLORS) % NUM_COLORS);
    return colorToString(this->selectedColor);
  }

  int moveColor(float coeff) {
    int changed = 0;

    float calculated_coeff;
    if (coeff > 0.5) {
      calculated_coeff = 5 + (coeff);
    } else {
      calculated_coeff = 5 + ((1-coeff));
    }

    std::cout << "calculated_coeff : " << calculated_coeff << std::endl;

    if (coeff < 0.5) {
      calculated_coeff = -calculated_coeff;
    }

    switch (this->selectedColor) {
    case colors::red: {
      this->red = constrainValue(static_cast<int>(this->red + calculated_coeff), 0, 255);
      changed = this->red;
      break;
    }
    case colors::green: {
      this->green = constrainValue(static_cast<int>(this->green + calculated_coeff), 0, 255);
      changed = this->green;
      break;
    }
    case colors::blue: {
      this->blue = constrainValue(static_cast<int>(this->blue + calculated_coeff), 0, 255);
      changed = this->blue;
      break;
    }
    }
    return changed;
  }
};

#endif // CPP_FCT_COLOR_HPP