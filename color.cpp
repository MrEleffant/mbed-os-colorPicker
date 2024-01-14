//
// Created by thiba on 29/11/2023.
//
#include "color.hpp"
#include <random>

unsigned long INT_TO_HEX_RGB(int r, int g, int b, int a) {
  return ((r & 0xff) << 24) + ((g & 0xff) << 16) + ((b & 0xff) << 8) +
         (a & 0xff);
}

int RND_INT_FOR_COLOR() {
  std::random_device rd;
  int seed = rd();

  srand(seed);

  int randomNumber = rand() % ((255 * 100) - (0 * 100) + 1) + (0 * 100);

  return randomNumber;
}

const char *color::colorToString(colors color) {
  switch (color) {
  case colors::red:
    return "Red";
  case colors::green:
    return "Green";
  case colors::blue:
    return "Blue";
  default:
    return "Unknown Color";
  }
}