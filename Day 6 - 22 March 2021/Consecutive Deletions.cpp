// Problem Link : https://www.codechef.com/COOK127C/problems/CONDEL

#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll findMinCost(ll N, ll K, ll* arr) {
    ll prefixSum[200005];
    ll totalOnes = arr[0];
    prefixSum[0] = arr[0];
    for(ll i = 1; i < N; ++i) {
        totalOnes += arr[i];
        prefixSum[i] = prefixSum[i-1] + arr[i];
    }
    if(K == N) return (totalOnes*(totalOnes+1))/2;
    ll L = 0, R = K-1;
    ll minSum = prefixSum[K-1];

    for(ll i = 1; i <= N-K; ++i) {
        ll tempSum = prefixSum[K+i-1] - prefixSum[i-1];
        if(tempSum < minSum) {
            L = i;
            R = K+L-1;
            minSum = tempSum;
        }
    }
    ll leftOnes = L == 0 ? 0 : prefixSum[L-1];
    ll rightOnes = R == N-1 ? 0 : prefixSum[N-1] - prefixSum[R];

    return ((minSum*(minSum+1))/2) + leftOnes + rightOnes;
}

int main() {
    ll T;
    cin >> T;

    while(T--) {
        ll N,K;
        cin >> N >> K;
        ll arr[200005];
        for(ll i = 0; i < N; ++i) {
            cin >> arr[i];
        }
        cout << findMinCost(N,K,arr) << endl;
    }
    return 0;
}
