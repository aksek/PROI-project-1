#include<iostream>
#include<cstdlib>
#include<time.h>
#include"../include/SetOfInts.h"

using namespace std;

int main() {
	SetOfInts a;
	srand(time(NULL));
	for(int i = 0; i < 12; ++i) {
		a += i;
	}
	a -= 5;
	a.show();
	
	SetOfInts b;
	for (int i = 10; i < 15; i += 2) {
		b += i;
	}
	b.show();
	a += b;
	a.show();
	return 0;
}