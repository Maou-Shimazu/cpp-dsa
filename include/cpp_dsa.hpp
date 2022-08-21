#pragma once

#ifndef CPP_DSA_HPP
#define CPP_DSA_HPP

#include "console_log.hpp"
#include <algorithm>
#include <array>
#include <boost/algorithm/string.hpp>
#include <cassert>
#include <cmath>
#include <cstdint>
#include <doctest/doctest.h>
#include <fmt/core.h>
#include <fmt/format.h>
#include <functional>
#include <iostream>
#include <memory>
#include <src/format.cc>
#include <sstream>
#include <vector>

using namespace console;
using ll = log_level;

void DECORATION(const char* name) {
	std::cout << "\n======================================== " << name
			  << " =======================================\n";
}

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

namespace Stack {
	class Stack {
		static constexpr int SMAX = 10;
		int size				  = 0;
		std::array<int, SMAX> items;
		uint64_t top;

	public:
		Stack() : top(std::move(static_cast<uint64_t>(-1))){};
		std::function<bool()> is_full = [this] {
			return top == SMAX - 1 ? 1 : 0;
		};
		std::function<bool()> is_empty = [this] { return top == -1 ? 1 : 0; };

		void push(int new_item) {
			if (is_full())
				std::cout << "STACK IS FULL";
			else {
				top++;
				items[top] = new_item;
			}
			size++;
		}

		void push(std::vector<int> new_items) {
			if (is_full())
				std::cout << "Stack is full";
			else {
				for (auto& i : new_items) {
					top++;
					items[top] = i;
				}
			}
			size += new_items.size();
		}

		void pop() {
			if (is_empty())
				std::cout << "\n STACK IS EMPTY \n";
			else {
				std::cout << "Item Popped = " << items[top] << "\n";
				top--;
			}
			size--;
		}

		void printStack() {
			std::cout << "Stack: ";
			for (uint64_t i = 0; i < size; i++) {
				std::cout << items[i] << " ";
			}
			std::cout << "\n";
		}
	};

	int main() {
		DECORATION("Stack");
		Stack s = Stack();
		// s.push(1);
		// s.push(2);
		// s.push(3);
		// s.push(4);
		s.push({1, 2, 3, 4});
		s.printStack();
		s.pop();
		std::cout << "\nAfter popping out\n";
		s.printStack();
		std::cout << std::endl;
		return 0;
	}
} // namespace Stack

namespace Queue {
	class Queue {
		static constexpr int SIZE = 5;
		std::array<int, SIZE> items;
		uint64_t front, rear;
		static constexpr uint64_t N_ONE = static_cast<uint64_t>(-1);

	public:
		Queue() : front(std::move(N_ONE)), rear(std::move(N_ONE)) {}
		bool is_full() {
			return front == 0 && rear == SIZE - 1 ? true : false;
		}
		bool is_empty() {
			return front == -1 ? true : false;
		}
		void en_queue(int element) {
			if (is_full())
				console::log(
					fmt::format("Queue is full! Tried to insert: {}", element),
					ll::Warning,
					std::cerr);
			else {
				if (front == -1)
					front = 0;
				rear++;
				items[rear] = element;
				console::log(fmt::format("Inserted = {}", element));
			}
		}
		void en_queue(std::vector<int> elements) {

			for (auto& i : elements) {
				if (is_full())
					console::log(
						fmt::format("Queue is full! Tried to insert: {}", i),
						ll::Warning,
						std::cerr);
				if (front == -1)
					front = 0;
				rear++;
				items[rear] = i;
				console::log(fmt::format("Inserted = {}", i), ll::Success);
			}
		}
		int de_queue() {
			if (is_empty()) {
				console::log("Queue is Empty", ll::Error, std::cerr);
				return -1;
			} else {
				int element = items[front];
				if (front >= rear) {
					front = N_ONE;
					rear  = N_ONE;
				} else
					front++;
				console::log(fmt::format("Deleted = ", element), ll::Success);
				return element;
			}
		}
		void display() {
			if (is_empty())
				console::log("Queue is Empty", ll::Error, std::cerr);
			else {
				console::log(fmt::format("Front index = {}", front));
				std::cout << "Items: ";
				for (auto i = front; i <= rear; i++)
					std::cout << items[i] << " ";
				std::cout << std::endl;
				console::log(fmt::format("Rear Index = {}", rear));
			}
		}
	};
	int main() {
		DECORATION("Queue");
		Queue q = Queue();
		q.de_queue();
		// q.en_queue(1);
		// q.en_queue(2);
		// q.en_queue(3);
		// q.en_queue(4);
		// q.en_queue(5);
		q.en_queue({1, 2, 3, 4, 5});
		q.en_queue(6); // queue is full
		q.display();

		q.de_queue();
		q.display();

		std::cout << "\n";
		return 0;
	}
} // namespace Queue

namespace CircularQueue { // warning: has bugs in output
	class CircularQueue {
		static constexpr int SIZE{5};
		static constexpr uint64_t N_ONE = static_cast<uint64_t>(-1);
		std::array<int, 5> items;
		uint64_t front, rear;

	public:
		CircularQueue() : front(std::move(N_ONE)), rear(std::move(N_ONE)) {}
		bool is_full() {
			return front == 0 && rear == SIZE - 1 ? true
				   : front == rear + 1			  ? true
												  : false;
		}
		bool is_empty() {
			return front == -1 ? true : false;
		}
		void en_queue(int element) {
			if (is_full())
				console::log("Queue is full", ll::Error, std::cerr);
			else {
				if (front == -1)
					front = 0;
				rear		= (rear + 1) % SIZE;
				items[rear] = element;
				console::log(fmt::format("Inserted = {}", element),
							 ll::Success);
			}
		}
		int de_queue() {
			if (is_empty()) {
				console::log("Queue is empty", ll::Error, std::cerr);
				return -1;
			} else {
				int element = items[front];
				if (front == rear) {
					front = N_ONE;
					rear  = N_ONE;
				} else
					front = (front + 1) % SIZE;
				return element;
			}
		}
		void display() {
			if (is_empty())
				console::log("Queue is empty", ll::Error, std::cerr);
			else {
				console::log(fmt::format("Front = {}", front));
				std::cout << "\nItems: ";
				for (auto i = front; i != rear; i = (i + 1) % SIZE)
					std::cout << items[i];
				std::cout << "\n";
				console::log(fmt::format("Rear = {}", rear));
			}
		}
	};
	int main() {
		DECORATION("Circular Queue");
		CircularQueue q = CircularQueue();

		// Fails because front = -1
		q.de_queue();

		q.en_queue(1);
		q.en_queue(2);
		q.en_queue(3);
		q.en_queue(4);
		q.en_queue(5);

		// q.en_queue({1, 2, 3, 4, 5});

		// Fails to enqueue because front == 0 && rear == SIZE - 1
		q.en_queue(6);

		q.display();

		int elem = q.de_queue();

		if (elem != -1)
			console::log(fmt::format("Deleted Element is = {}", elem));

		q.display();

		q.en_queue(7);

		q.display();

		q.en_queue(8);
		std::cout << std::endl;
		return 0;
	}
} // namespace CircularQueue

namespace List {
	template <class T>
	struct Node {
		T data;
		Node* next;
		Node() = default;
		explicit Node(T data, Node* next)
			: data(std::move(data)), next(std::move(next)) {}
		~Node() = default;
	};
	template <class T>
	void display(Node<T>* n) {
		while (n != nullptr) {
			std::cout << n->data << " ";
			n = n->next;
		}
	}
	template <class T>
	class List {
		Node<T>*head, *tail;

	public:
		List() : head(std::move(nullptr)), tail(std::move(nullptr)) {}
	};
	int main() {
		std::unique_ptr<Node<std::string>> third =
			std::make_unique<Node<std::string>>(
				Node<std::string>("three", nullptr));
		std::unique_ptr<Node<std::string>> second =
			std::make_unique<Node<std::string>>(
				Node<std::string>("two", third.get()));
		std::unique_ptr<Node<std::string>> head =
			std::make_unique<Node<std::string>>(
				Node<std::string>("one", second.get()));
		display(head.get());
		return 0;
	}
} // namespace List

#endif