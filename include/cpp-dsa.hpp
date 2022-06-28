#pragma once

#ifndef CPP_DSA_HPP
#define CPP_DSA_HPP

#include <cmath>
#include <sstream>
#include <iostream>
#include <fmt/core.h>
#include <fmt/format.h>
#include <src/format.cc>
#include <doctest/doctest.h>
#include <boost/algorithm/string.hpp>

namespace basic {
    // Algo1
    template <typename T, typename H> constexpr auto add(T a, H b) noexcept {
        return a + b;
    }

    // Algo2
    template <typename T, typename H, typename M> constexpr auto largest(T a, H b, M c) noexcept {
        return a > b && a > c ? a : b > c && b > a ? b : c;
    }

    // Algo3
    template <typename T, typename H, typename M> constexpr auto quadratic(T a, H b, M c) noexcept {
        auto D = b * b - 4 * a * c;
        if (D >= 0) {
            auto r1 = (-b + std::sqrt(D)) / (2 * a);
            auto r2 = (-b - std::sqrt(D)) / (2 * a);
            return fmt::format("{} and {}", r1, r2);
        } else {
            auto rp = -b / (2 * a);
            auto ip = std::sqrt(-D) / (2 * a);
            return fmt::format("{}+j({}) and {}-j({})", rp, ip, rp, ip);
        }
    }

    // Algo4
    template <typename T> constexpr auto factorial(T n) noexcept {
        auto factorial = 1;
        for (auto i = 1; i <= n; ++i) {
            factorial *= i;
        }
        return factorial;
    }

    // Algo5
    template <typename T> constexpr auto is_prime(T n) noexcept {
        auto flag = 1;
        for (auto i = 2; i <= n / 2; i++) {
            if (n % i == 0) { flag = 0; break; }
        }
        return flag;
    }

    // Algo6
    template <typename T> const auto fibonacci(T n) noexcept {
        std::stringstream ss;
        auto first_term = 0, second_term = 1, temp = NULL;
        while (second_term < n) {
            temp = second_term;
            second_term = second_term + first_term;
            first_term = temp;
            ss << second_term << " ";
        }
        return ss.str();
    }
} // namespace basic

#endif