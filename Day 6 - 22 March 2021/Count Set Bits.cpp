// Count number of 1s in binary representation of an integer

// Input Format
// Input N = Number of Test Cases, followed by N numbers

// Constraints
// None

// Output Format
// Number of Set Bits in each number each in a new line

#include<iostream>
using namespace std;

int countSetBits(int n) {
	int count = 0;

	while(n > 0) {
		count += (n & 1);
		n = n >> 1;
	}
	return count;
}

int main() {
	int T;
	cin >> T;
	while(T--) {
		int n;
		cin >> n;
		cout << countSetBits(n)<< endl;
	}
	return 0;
}