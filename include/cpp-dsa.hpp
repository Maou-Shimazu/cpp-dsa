#pragma once

#ifndef CPP_DSA_HPP
#define CPP_DSA_HPP

#include <boost/algorithm/string.hpp>
#include <cmath>
#include <cstdint>
#include <cstdlib> //mmmmmmmmmmm
#include <doctest/doctest.h>
#include <fmt/core.h>
#include <fmt/format.h>
#include <functional>
#include <iostream>
#include <src/format.cc>
#include <sstream>
#include <utility>

namespace basic {
	// Algo1
	template <typename T, typename H>
	constexpr auto add(T a, H b) noexcept {
		return a + b;
	}

	// Algo2
	template <typename T, typename H, typename M>
	constexpr auto largest(T a, H b, M c) noexcept {
		return a > b && a > c ? a : b > c && b > a ? b : c;
	}

	// Algo3
	template <typename T, typename H, typename M>
	constexpr auto quadratic(T a, H b, M c) noexcept {
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
	template <typename T>
	constexpr auto factorial(T n) noexcept {
		auto factorial = 1;
		for (auto i = 1; i <= n; ++i) {
			factorial *= i;
		}
		return factorial;
	}

	// Algo5
	template <typename T>
	constexpr auto is_prime(T n) noexcept {
		auto flag = 1;
		for (auto i = 2; i <= n / 2; i++) {
			if (n % i == 0) {
				flag = 0;
				break;
			}
		}
		return flag;
	}

	// Algo6
	template <typename T>
	const auto fibonacci(T n) noexcept {
		std::stringstream ss;
		auto first_term = 0, second_term = 1, temp = NULL;
		while (second_term < n) {
			temp		= second_term;
			second_term = second_term + first_term;
			first_term	= temp;
			ss << second_term << " ";
		}
		return ss.str();
	}
} // namespace basic

namespace CStack {
#include <cstdlib>
#include <iostream>

	using namespace std;

#define MAX 10
	int size = 0;

	// Creating a stack
	struct stack {
		int items[MAX];
		int top;
	};
	typedef struct stack st;

	void createEmptyStack(st* s) {
		s->top = -1;
	}

	// Check if the stack is full
	int isfull(st* s) {
		if (s->top == MAX - 1)
			return 1;
		else
			return 0;
	}

	// Check if the stack is empty
	int isempty(st* s) {
		if (s->top == -1)
			return 1;
		else
			return 0;
	}

	// Add elements into stack
	void push(st* s, int newitem) {
		if (isfull(s)) {
			cout << "STACK FULL";
		} else {
			s->top++;
			s->items[s->top] = newitem;
		}
		size++;
	}

	// Remove element from stack
	void pop(st* s) {
		if (isempty(s)) {
			cout << "\n STACK EMPTY \n";
		} else {
			cout << "Item popped= " << s->items[s->top];
			s->top--;
		}
		size--;
		cout << endl;
	}

	// Print elements of stack
	void printStack(st* s) {
		printf("Stack: ");
		for (int i = 0; i < size; i++) {
			cout << s->items[i] << " ";
		}
		cout << endl;
	}

	// Driver code
	int _main() {
		std::cout << "CStack Output: " << std::endl;
		st* s = (st*)malloc(sizeof(st));

		createEmptyStack(s);

		push(s, 1);
		push(s, 2);
		push(s, 3);
		push(s, 4);

		printStack(s);

		pop(s);

		cout << "\nAfter popping out\n";
		printStack(s);
		std::cout << std::endl;
		return 0;
	}

} // namespace CStack

namespace Stack {
	class Stack {
		static constexpr int SMAX = 10;
		int size				  = 0;
		std::array<int, SMAX> items;
		uint64_t top;

	public:
		Stack() : top(std::move(static_cast<uint64_t>(-1))){};
		std::function<bool()> is_full = [this] {
			return this->top == this->SMAX - 1 ? 1 : 0;
		};
		std::function<bool()> is_empty = [this] {
			return this->top == -1 ? 1 : 0;
		};

		void push(int new_item) {
			if (this->is_full())
				std::cout << "STACK IS FULL";
			else {
				this->top++;
				this->items[this->top] = new_item;
			}
			this->size++;
		}

		void pop() {
			if (this->is_empty())
				std::cout << "\n STACK IS EMPTY \n";
			else {
				std::cout << "Item Popped = " << this->items[this->top] << "\n";
				this->top--;
			}
			this->size--;
		}

		void printStack() {
			std::cout << "Stack: ";
			for (uint64_t i = 0; i < this->size; i++) {
				std::cout << this->items[i] << " ";
			}
			std::cout << "\n";
		}
	};

	int _main() {
		std::cout << "Stack Output: " << std::endl;
		Stack s = Stack();

		s.push(1);
		s.push(2);
		s.push(3);
		s.push(4);
		s.printStack();
		s.pop();
		std::cout << "\nAfter popping out\n";
		s.printStack();
		std::cout << std::endl;
		return 0;
	}
} // namespace Stack

#endif