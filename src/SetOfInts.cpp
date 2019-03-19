
#include<iostream>
#include<list>
#include"../include/SetOfInts.h"

using namespace std;

int SetOfInts::getFirst() {
	int firstElement = nums.front();
	nums.pop_front();
	return firstElement;
}

bool SetOfInts::empty() const{
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

SetOfInts& SetOfInts::operator+= (const int other) {
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
	for (; it != nums.end(); ++it) {
		while (toErase < *it && !other.empty())
			toErase = other.getFirst();
		if (*it == toErase) {
			it = nums.erase(it);
			--it;
			
		}
	}
	return *this;
}

SetOfInts& SetOfInts::operator-= (const int other) {
	for (auto it = nums.begin(); it != nums.end(); ++it) {
		if (*it == other) {
			nums.erase(it);
			break;
		}
	}
	return *this;
}

SetOfInts& SetOfInts::increment() {
	for (auto it = nums.begin(); it != nums.end(); ++it) 
		++(*it);
	return *this;
}

SetOfInts& SetOfInts::decrement() {
	for (auto it = nums.begin(); it != nums.end(); ++it) 
		--(*it);
	return *this;
}

void SetOfInts::show() const{
	auto it = nums.begin();
	cout << "{";
	if (it != nums.end())
		cout << *it;
	++it;
	for (; it != nums.end(); ++it) 
		cout << ", " << *it;
	cout << "}\n";
}

void SetOfInts::show(string message) const{
	auto it = nums.begin();
	cout << message << "{";
	if (it != nums.end())
		cout << *it;
	++it;
	for (; it != nums.end(); ++it) 
		cout << ", " << *it;
	cout << "}\n";
}