#include"../include/SetOfInts.h"
#include<iostream>


SetOfInts& SetOfInts::operator+= (SetOfInts& other) {}

SetOfInts& SetOfInts::operator+= (int other) {
	auto last = --nums.end();
	if (nums.empty() || *last < other) {
		nums.push_back(other);
		return *this;
	} else {
		for (auto it = nums.begin(); it != nums.end(); ++it) {
			if (*it == other) {
				break;
			} else if (other < *it) {
				nums.emplace(it, other);
				return *this;
			}
		}
		
	}
}

SetOfInts& SetOfInts::operator-= (SetOfInts& other) {}

SetOfInts& SetOfInts::operator-= (int other) {}

void SetOfInts::show() {
	auto it = nums.begin();
	std::cout << "{" << *it;
	++it;
	for (; it != nums.end(); ++it) 
		std::cout << ", " << *it;
	std::cout << "}\n";
}

void SetOfInts::show(int min, int max) {
	std::cout << "{";
	auto it = nums.begin();
	while (*it < min)
		++it;
	std::cout << *it;
	++it;
	for (; it != nums.end(); ++it) 
		if (*it >= min && *it <= max)
			std::cout << ", " << *it;
	std::cout << "}\n";
}