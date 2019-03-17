
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
	int empty();
	SetOfInts& operator+= (SetOfInts other);
	SetOfInts& operator+= (int other);
	SetOfInts& operator-= (SetOfInts other);
	SetOfInts& operator-= (int other);
	SetOfInts& increment();
	SetOfInts& decrement();
	void show();
	void show(std::string message);
};

#endif //SETOFINTS_H