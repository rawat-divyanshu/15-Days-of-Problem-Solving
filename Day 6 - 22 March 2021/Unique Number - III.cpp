// We are given an array containg n numbers. All the numbers are present thrice except for one number which is only present once.
// Find the unique number. Only use - bitwise operators, and no extra space.

// Input Format
// First line contains the number n. Second line contains n space separated number.

// Constraints
// N < 10^5

// Output Format
// Output a single line containing the unique number

#include<iostream>
using namespace std;

int foundUniqueNumber(int* arr, int n) {
	int num = 0;
	for(int i = 0; i < 32; ++i) {
		int bitSum = 0;
		for(int j = 0; j < n; ++j) {
			bitSum += (arr[j] >> i) & 1;
		}
		int k = bitSum % 3;
		num = (k << i) | num;
	}
	return num;
}

int main() {
	int n;
	cin >> n;
	int* arr = new int[n];

	for(int i = 0; i < n; ++i)
		cin >> arr[i];

	cout << foundUniqueNumber(arr,n) << endl;
	return 0;
}