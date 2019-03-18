
#ifndef SETOFINTS_H
#define SETOFINTS_H

#include<iostream>
#include<list>
#include<string>

class SetOfInts{
private: 
	std::list<int> nums;
public:
	int getFirst();
	bool empty() const;
	SetOfInts& operator+= (SetOfInts other);
	SetOfInts& operator+= (const int other);
	SetOfInts& operator-= (SetOfInts other);
	SetOfInts& operator-= (const int other);
	SetOfInts& increment();
	SetOfInts& decrement();
	void show() const;
	void show(std::string message) const;
};

#endif //SETOFINTS_H