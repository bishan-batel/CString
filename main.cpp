/*
 * Created by bishan_ on 2/14/24.
*/

#include <iostream>

#include "Tests.hpp"
#include "utils.hpp"

int main(const i32 argc, const char* const argv[]) {
  if (argc <= 1) {
    return Tests::run_all();
  }

  return Tests::run(argv[1]);
}
