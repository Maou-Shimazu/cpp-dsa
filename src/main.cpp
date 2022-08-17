#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "cpp_dsa.hpp"
#include "c_based_impls.hpp"

TEST_CASE("basic") {
    CHECK(basic::add(1, 2) == 3);
    CHECK(basic::largest(456, 67, 234) == 456);
    CHECK(basic::quadratic(1, 2, 3) == "-1+j(1.4142135623730951) and -1-j(1.4142135623730951)");
    CHECK(basic::factorial(5) == 120);
    CHECK(basic::is_prime(2) == true);
    CHECK(boost::trim_copy(std::string(basic::fibonacci(5))) == "1 2 3 5");
}

TEST_CASE("stack") {
    CHECK(CStack::_main() == 0);
    CHECK(Stack::_main() == 0);
}