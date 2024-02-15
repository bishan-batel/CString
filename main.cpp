#include <iostream>

#include "c_string.hpp"

int main() {
  CString string{"bruh"};

  std::cout << string << std::endl;
  //
  // string += CString(" moment");
  //
  // std::cout << string << std::endl;

  return 0;
}
