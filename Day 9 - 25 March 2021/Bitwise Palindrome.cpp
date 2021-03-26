// Check if the binary representation of a number is palindrome or not.

// Input Format
// First line contains T - no of testcases. Next T lines contain one integer each containing the input N.

// Constraints
// 1 <= T <= 10000
// 1 <= N <= 1018
// Expected Time Complexity: O(log N)
// Expected Space Complexity: O(logN)

// Output Format
// Print "true" or "false" (without quotes) for each testcase in a new line.


#include<iostream>
#include<string>
using namespace std;

string isBitwisePalindrome(int n) {
	int tempN = n;
	int numberOfBits = 0;

	while(tempN > 0) {
		++numberOfBits;
		tempN = tempN >> 1;
	}

	for(int i = 0; i < numberOfBits/2; ++i) {
		int bit1 = (n >> i) & 1;
		int bit2 = (n >> (numberOfBits - i - 1)) & 1;
		if(bit1 != bit2) {
			return "false";
		}
	}
	return "true";
}

int main () {
	int q;
	cin >> q;

	while(q--) {
		int n;
		cin >> n;
		cout << isBitwisePalindrome(n) << endl;
	}
	return 0;
}