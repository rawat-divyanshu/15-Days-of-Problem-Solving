// Given a positive integer, output its complement number. The complement strategy is to flip the bits of its binary representation.

// Note:
// 1. You could assume no leading zero bit in the integer’s binary representation.

// Input Format
// Input positive integer n

// Constraints
// The given integer is guaranteed to fit within the range of a 32-bit signed integer.

// Output Format
// Print the integer after flipping bits of n.

#include<iostream>
using namespace std;

int findComplement(int n) {
	if(n == 0) return 1;

	int num = 0;
	for(int i = 0; n > 0 && i < 32; ++i) {
		int k = n & 1;
		if(k == 0) {
			num = (1 << i) | num;
		}
		n = n >> 1;
	}
	return num;
}

int main () {
	int n;
	cin >> n;
	cout << findComplement(n) << endl;
	return 0;
}