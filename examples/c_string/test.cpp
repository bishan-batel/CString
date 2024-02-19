#include <format>
#include <iostream>

#include "c_string.hpp"
#include "Tests.hpp"

TEST(c_string) {
  CString bruh{"bruh"};
  const CString moment{"moment"};

  std::cout << bruh << std::endl;

  bruh += moment;

  std::cout << bruh << std::endl;
}
