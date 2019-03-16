
#include<iostream>
#include<list>
#include"../include/SetOfInts.h"

int SetOfInts::getFirst() {
	int firstElement = nums.front();
	nums.pop_front();
	return firstElement;
}

int SetOfInts::empty() {
	return nums.empty();
}

SetOfInts& SetOfInts::operator+= (SetOfInts other) {
	int toEmplace = other.getFirst();
	for (auto it = nums.begin(); it != nums.end() && !other.empty(); ++it) {
		if (*it == toEmplace)
			toEmplace = other.getFirst();
		else if (toEmplace < *it) {
			nums.emplace(it, toEmplace);
			toEmplace = other.getFirst();
		}
	}
	do {
		nums.push_back(toEmplace);
		toEmplace = other.getFirst();
	} while (!other.empty());
	nums.push_back(toEmplace);
	return *this;
}

SetOfInts& SetOfInts::operator+= (int other) {
	auto last = --nums.end();
	if (nums.empty() || *last < other) {
		nums.push_back(other);
	} else {
		for (auto it = nums.begin(); it != nums.end(); ++it) {
			if (*it == other) {
				break;
			} else if (other < *it) {
				nums.emplace(it, other);
				break;
			}
		}
	}
	return *this;
}

SetOfInts& SetOfInts::operator-= (SetOfInts other) {
	int toErase = other.getFirst();
	auto it = nums.begin();
	for (; it != nums.end() && !other.empty(); ++it) {
		if (*it == toErase) {
			it = nums.erase(it);
			it--;
			toErase = other.getFirst();
		}
	}
	if (*it == toErase) 
		nums.erase(it);
	return *this;
}

SetOfInts& SetOfInts::operator-= (int other) {
	for (auto it = nums.begin(); it != nums.end(); ++it) {
		if (*it == other) {
			nums.erase(it);
			break;
		}
	}
	return *this;
}

void SetOfInts::show() {
	auto it = nums.begin();
	std::cout << "{";
	if (it != nums.end())
		std::cout << *it;
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