// It is Alex’s birthday and she wants to go shopping. She only has ‘A’ units of money and she wants to spend all of her money.
// However, she can only purchase one kind of item. She goes to a shop which has ‘n’ types items with prices A0,A1,A2,…,An-1.
// The shopkeeper claims that he has atleast ‘k’ items she can choose from. Help her find out if the shopkeeper is correct or not.

// Input Format
// The first line contains an integer ‘n’ denoting the number of items in the shop.
// The second line contains ‘n’ space-separated integers describing the respective price of each item.
// The third line contains an integer ‘q’ denoting the number of queries.
// Each of the subsequent lines contains two space-separated integers ‘A’ and ‘k’

// Constraints
// 1 <=n, Ai, A <= 105 where 0<=i
// 1 <= q <= 2*n
// 1 <= k <= n
// The array may contain duplicate elements.

// Output Format
// For each query, print Yes on a new line if the shopkeeper is correct; otherwise, print No instead.

#include<iostream>
#include<string>
using namespace std;

string isShopkeeperCorrect(int A, int K, int N, int* items) {
	if(N < K) return "NO";
	int canBePurchasedItems = 0;

	for(int i = 0; i < N; ++i) {
		if(A % items[i] == 0) {
			++canBePurchasedItems;
		}
	}
	return canBePurchasedItems >= K ? "Yes" : "No";
}

int main() {
	int N;
	cin >> N;

	int* items = new int[N];

	for(int i = 0; i < N; ++i)
		cin >> items[i];

	int Q;
	cin >> Q;

	while(Q--) {
		int A,K;
		cin >> A >> K;
		cout << isShopkeeperCorrect(A,K,N,items) << endl;
	}
	return 0;
}