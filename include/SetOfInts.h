
#ifndef SETOFINTS_H
#define SETOFINTS_H

#include<iostream>
#include<list>

class SetOfInts{
private: 
	std::list<int> nums;
public:
	SetOfInts& operator+= (SetOfInts& other);
	SetOfInts& operator+= (int other);
	SetOfInts& operator-= (SetOfInts& other);
	SetOfInts& operator-= (int other);
	void show();
	void show(int min, int max);
};

#endif //SETOFINTS_H