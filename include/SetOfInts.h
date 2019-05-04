
/*  Assignment:   Project #1
 *      Author:   Aniela Kosek, 300234
 *      Grader:   Wiktor Kuśmirek
 */

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
	SetOfInts& increment();			//increments all elements by 1
	SetOfInts& decrement();			//decrements all elements by 1
	void show() const;			//format: {...}
	void show(std::string message) const;	//can be used for displaying "A = {...}"
};

#endif //SETOFINTS_H
