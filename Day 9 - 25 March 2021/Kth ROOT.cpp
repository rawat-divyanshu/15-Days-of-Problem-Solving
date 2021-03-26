// You are given two integers n and k. Find the greatest integer x, such that, x^k <= n.

// Input Format
// First line contains number of test cases, T. Next T lines contains integers, n and k.

// Constraints
// 1<=T<=10
// 1<=N<=10^15
// 1<=K<=10^4

// Output Format
// Output the integer x

#include<bits/stdc++.h>
#define ll long long
using namespace std;

bool isPossibleX(ll x, ll k, ll n) {
	return pow(x,k) <= n;
}

ll searchX(ll n, ll k) {
	ll l = 0, r = n;
	ll ans = -1;

	while(l <= r) {
		ll m = l + (r-l)/2;
		if(isPossibleX(m,k,n)) {
			ans = m;
			l = m+1;
		} else {
			r = m-1;
		}
	}
	return ans;
}

int main() {
	ll Q;
	cin >> Q;

	while(Q--) {
		ll n,k;
		cin >> n >> k;
		cout << searchX(n,k) << endl;
	}
	return 0;
}