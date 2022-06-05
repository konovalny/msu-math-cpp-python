#include <iostream>
#include "myClass.hpp"

int main(void) {
  myClass obj(0);
  std::cout << obj.getChangedNumber() << std::endl;
}