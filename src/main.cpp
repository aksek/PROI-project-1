#include<iostream>
#include<cstdlib>
#include<time.h>
#include"../include/SetOfInts.h"

using namespace std;

int main() {
	SetOfInts a;
	srand(time(NULL));
	for(int i = 0; i < 25; ++i) {
		a += rand() % 1000;
	}
	a.show(100, 200);
	return 0;
}