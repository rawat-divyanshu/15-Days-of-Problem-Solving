// A peak element is an element that is greater than its neighbors.

// Given an input array arr, where arr[i] ≠ arr[i+1], find a peak element if exists return true else return false.
// You may imagine that arr[ -1 ] = arr[ n ] = -∞.

// Input Format
// A single integer, N, denoting the number of elements in array. Next line contains N integers, denoting the elements of array.

// Constraints
// n<1000000

// Output Format
// if peak element is present print true else print false

#include<iostream>
#include<string>
using namespace std;


string hasPeak(int n, int* nums) {
	for(int i = 1; i < n-1; ++i) {
		if(nums[i] > nums[i-1] && nums[i] > nums[i+1]) {
			return "true";
		}
	}
	return "false";
}

int main() {
	int n;
	cin >> n;

	int* nums = new int[n];

	for(int i = 0; i < n; ++i)
		cin >> nums[i];

	cout << hasPeak(n,nums) << endl;
	return 0;
}