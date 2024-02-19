//
// Created by bishan_ on 2/18/24.
//

#ifndef TEST_HPP
#define TEST_HPP
#include <functional>
#include <iostream>
#include <memory>
#include <ranges>
#include <unordered_map>

#include "utils.hpp"


#define TEST(name) \
void __test_ ## name ## __func ();\
static inline const unit __test_ ## name = \
  Tests::add(#name, []{\
   __test_ ## name ## __func ();\
   return 0;\
}); \
void __test_ ## name ## __func ()

/**
 * \brief Tests Singleton that is used to easily create tests / example code
 * that is run
 */
class Tests {
  inline static std::unique_ptr<Tests> instance = nullptr;

  using Name = const char*;
  std::unordered_map<Name, std::function<i32()>> tests{};

  static Tests& get();

public:
  /**
   * \brief Registers a new test with the given name, returns
   * unit to be able to run this function in a non-local context
   *
   * Example:
   * static auto my_test = Tests::add("my_test", []{
   *   std::cout << "huh" << std::endl;
   *   return 0;
   * });
   */
  static unit add(const Name name, const std::function<i32()>& func) {
    if (get().tests.contains(name)) {
      std::cerr << "Duplicate test name '" << name << "'" << std::endl;
      return {};
    }

    get().tests[name] = func;
    return {};
  }

  /**
   * \brief Runs all registered tests
   */
  static i32 run_all() {
    // run all tests
    for (const auto& name : get().tests | std::views::keys) {
      if (const auto code = run(name)) {
        // if test failed propogate error
        return code;
      }
    }
    return 0;
  }

  /**
   * \brief Attempts to run test with given name
   */
  static i32 run(const Name name) {
    if (not get().tests.contains(name)) {
      std::cout << "No Test with the name '" << name << "'" << std::endl;
      return -1;
    }

    std::cout << "Running '" << name << "' Test" << std::endl;

    if (const i32 code = get().tests.at(name)()) {
      std::cerr << "\t Test failed with code " << code << std::endl;
      return code;
    }

    std::cout << std::endl;

    return 0;
  }
};

inline Tests& Tests::get() {
  if (not instance) instance = std::make_unique<Tests>();
  return *instance;
}

#endif //TEST_HPP
