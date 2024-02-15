#include <iostream>

#include "c_string.hpp"

int main() {
  CString bruh{"bruh"};
  CString moment{"moment"};

  std::cout << bruh << std::endl;
  bruh += moment;

  std::cout << bruh << std::endl;
  return 0;
}
