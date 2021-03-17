// You are given an array arr of size N. You need to print the total count of sub-arrays having their sum equal to 0

// Input Format
// First line of the input contains an integer T denoting the number of test cases
// For each test case :
// Line 1 : N the size of Array
// Line 2 : N elements for Array

// Constraints
// 1 <= T <= 100
// 1 <= N <= 10^6
// -10^10 <= Ai <= 10^10

// Output Format
// For each test case, in a new line, print the total number of subarrays whose sum is equal to 0.

#include <bits/stdc++.h>
using namespace std;

int zeroSumSubarrayCount(int n, int* arr) {
    int* prefixSum = new int[n];
    unordered_map<int,int> eleCount;
    prefixSum[0] = arr[0];
    if(arr[0] != 0) {
        eleCount[0] = 1;
        eleCount[prefixSum[0]] = 1;
    } else {
        eleCount[0] = 2;
    }

    for(int i = 1; i < n; ++i) {
        prefixSum[i] = arr[i] + prefixSum[i-1];
        if(eleCount.find(prefixSum[i]) == eleCount.end()) {
            eleCount[prefixSum[i]] = 1;
        } else {
            eleCount[prefixSum[i]]++;
        }
    }
    int count = 0;
    for(auto key: eleCount) {
        int val = key.second;
        if(val > 1) {
            count += val*(val-1)/2;
        }
    }
    return count;
}

int main() {
    int T;
    cin >> T;

    while(T--) {
        int n;
        cin >> n;
        int* arr = new int[n];
        for(int i = 0; i < n; ++i) {
            cin >> arr[i];
        }
        cout << zeroSumSubarrayCount(n,arr) << endl;
    }
    return 0;
}
