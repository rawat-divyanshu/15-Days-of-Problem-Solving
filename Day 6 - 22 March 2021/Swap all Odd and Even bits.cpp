// Given an unsigned integer, swap all odd bits with even bits.
// For example, if the given number is 23 (00010111), it should be converted to 43 (00101011).
// Every even position bit is swapped with adjacent bit on right side , and every odd position bit is swapped with adjacent on left side.

// Input Format
// First line contains T - no of testcases. Next T lines contain one integer each containing the input N.

// Constraints
// Expected time complexity for each testcase - O(1)
// Expected space complexity for each testcase - O(1)

// Output Format
// Print output for each testcases in a new line.

#include<iostream>
using namespace std;

int swapBits(int n) {
	int ans = 0;

	for(int i = 0; n > 0 && i < 32; i += 2) {
		int evenBit = n & 1;
		int oddBit = (n >> 1) & 1;

		ans = ans | (evenBit << (i+1)) | (oddBit << i);
		n = n >> 2;
	}
	return ans;
}

int main () {
	int T;
	cin >> T;
	while(T--) {
		int n;
		cin >> n;
		cout << swapBits(n) << endl;
	}
	return 0;
}