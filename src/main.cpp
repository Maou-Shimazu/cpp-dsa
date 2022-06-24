#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include <iostream>
#include "../include/cpp-dsa.hpp"

TEST_CASE("cpp-dsa") {
    CHECK(add(1, 2) == 3);
}
