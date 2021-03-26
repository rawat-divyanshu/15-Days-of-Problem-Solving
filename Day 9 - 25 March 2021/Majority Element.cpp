// Given an array of size n, find the majority element. The majority element is the element that appears more than ⌊ n/2 ⌋ times.

// You may assume that the array is non-empty and the majority element always exist in the array.

// Input Format
// First line contains integer N (size of the array) followed by N more integers.

// Constraints
// None

// Output Format
// Majority Element of array


#include<iostream>
using namespace std;

int findMajorityElement(int n, int* arr) {
	int majorityCount = 1;
	int majorityElement = arr[0];

	for(int i = 1; i < n; ++i) {
		if(arr[i] == majorityElement) {
			++majorityCount;
		} else {
			if(majorityCount == 0) {
				majorityCount = 1;
				majorityElement = arr[i];
			} else {
				--majorityCount;
			}
		}
	}
	return majorityElement;
}

int main () {
	int n;
	cin >> n;
	int* arr = new int[n];

	for(int i = 0; i < n; ++i)
		cin >> arr[i];

	cout << findMajorityElement(n,arr) << endl;
	return 0;
}