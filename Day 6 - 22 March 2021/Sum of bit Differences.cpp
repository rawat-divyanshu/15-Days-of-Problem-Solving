#include <bits/stdc++.h> 
using namespace std; 

int sumBitDifferences(int* arr, int n)  { 
	int ans = 0; 
	for (int i = 0; i < 32; i++) {
		int count = 0; 
		for (int j = 0; j < n; j++) 
			if ((arr[j] & (1 << i))) 
				count++;

		ans += (count * (n - count) * 2); 
	}
	return ans; 
}

int main() {
    int n;
    cin >> n;
    int* arr = new int[n];

    for(int i = 0; i < n; ++i)
        cin >> arr[i];
        
	cout << sumBitDifferences(arr, n) << endl; 
	return 0; 
} 
