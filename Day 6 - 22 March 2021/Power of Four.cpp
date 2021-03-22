// Given an integer, determine if it is a power of four or not. An integer n is a power of four, if there exists an integer x such that n == 4x.

// Input Format
// First line of input will contain an integer x.

// Constraints
// None

// Output Format
// Print "True" (without quotes) if x is a power of four. Print " False"(without quotes) if x is not power of four.

#include<iostream>
using namespace std;

bool isPowerOf4(int n) {
	if(n == 1) return true;
	int setBitPos = 0;
	for(int i = 1; n > 0; ++i) {
		if(n & 1) {
			setBitPos = i;
			n = n >> 1;
			break;
		}
		n = n >> 1;
	}
	if(n == 0 && setBitPos % 2 != 0) {
		return true;
	}
	return false;
}

int main () {
	int n;
	cin >> n;

	if(isPowerOf4(n)) {
		cout << "True" << endl;
	} else {
		cout << "False" << endl;
	}
	return 0;
}