#include "myClass.hpp"

myClass::myClass(int x) {
  this->x = x;
}

int myClass::getChangedNumber() {
  return x + 42;
}