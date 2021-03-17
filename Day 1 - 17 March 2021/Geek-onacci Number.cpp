// Problem Link : https://practice.geeksforgeeks.org/problems/geek-onacci-number/0/?page=1#

#include <bits/stdc++.h>
using namespace std;

int findNthGeekonacciNumber(int N, int* geekonacciNumbers) {
    if(N <= 3 || geekonacciNumbers[N] != 0) {
        return geekonacciNumbers[N];
    }
    return geekonacciNumbers[N] = findNthGeekonacciNumber(N-1,geekonacciNumbers) +
                                  findNthGeekonacciNumber(N-2,geekonacciNumbers) +
                                  findNthGeekonacciNumber(N-3,geekonacciNumbers);
}

int main() {
    int T;
    cin >> T;
    
    
    while(T--) {
        int N;
        int geekonacciNumbers[11] = {0};
        cin >> geekonacciNumbers[1];
        cin >> geekonacciNumbers[2];
        cin >> geekonacciNumbers[3];
        cin >> N;
        cout << findNthGeekonacciNumber(N,geekonacciNumbers) << endl;
    }
	return 0;
}