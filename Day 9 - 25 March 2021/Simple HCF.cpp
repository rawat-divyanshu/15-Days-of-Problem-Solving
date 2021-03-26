// Given N positive numbers, your task is to calculate their HCF.

// Input Format
// First line of input contains a single integer N, second line contains N space separated positive integers whose HCF is to be computed.

// Constraints
// N <= 10 and all the numbers lie between 1 and 100.

// Output Format
// Print HCF of N numbers.

#include <bits/stdc++.h>
using namespace std;

int gcd(int a, int b) {
    if (a == 0)
        return b;
    return gcd(b % a, a);
}

int findGCD(int* nums, int n) {
    int result = nums[0];
    for (int i = 1; i < n; i++){
        result = gcd(nums[i], result);
 
        if(result == 1) {
           return 1;
        }
    }
    return result;
}

int main() {
    int n;
	cin >> n;
	int* nums = new int[n];

	for(int i = 0; i < n; ++i)
		cin >> nums[i];
		
    cout << findGCD(nums, n) << endl;
    return 0;
}