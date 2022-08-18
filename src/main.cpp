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
    CHECK(CStack::main() == 0);
    CHECK(Stack::main() == 0);
}

TEST_CASE("Queue") {
    CHECK(CQueue::main() == 0);
    CHECK(Queue::main() == 0);
    CHECK(CCircularQueue::main() == 0);
    CHECK(CircularQueue::main() == 0);
}