#include<iostream>
#include<cstdlib>
#include<time.h>
#include"../include/SetOfInts.h"

using namespace std;

int main() {
	srand(time(NULL));
	
	SetOfInts A;
	A.show("A = ");
	A += 1;
	A.show("A += 1\nA = ");
	A -= 1;
	A.show("A -= 1\nA = ");
	
	cout << "adding 12 random numbers:\n";
	for(int i = 0; i < 12; ++i) {
		A += rand() % 100;
	}
	A.show("A = ");
	A -= 5;
	A.show("A -= 5\nA = ");
	
	SetOfInts B;
	B.show("B = ");
	B += A;
	B.show("B += A\nB = ");
	A -= B;
	A.show("A -= B\nA = ");
	
	cout << "incrementing B\n";
	B.increment();
	B.show("B = ");
	
	cout << "A += 100\n";
	A += 100;
	A.show("A = ");
	cout << "decrementing A\n";
	A.decrement();
	A.show();
	
	return 0;
}