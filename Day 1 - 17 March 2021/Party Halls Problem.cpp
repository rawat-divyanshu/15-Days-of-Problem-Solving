#include <bits/stdc++.h>
using namespace std;

int requiredPartyHalls(int n, int* startTime, int* endTime) {
    if(n <= 1) return n;

    sort(startTime,startTime+n);
    sort(endTime,endTime+n);

    int hallsCurrentlyInUse = 1;
    int requiredHalls = 1;

    int i = 1, j = 0;
    while(i < n) {
        if(startTime[i] >= endTime[j]) {
            --hallsCurrentlyInUse;
        } else {
            ++hallsCurrentlyInUse;
        }
        requiredHalls = max(requiredHalls,hallsCurrentlyInUse);
        ++i;             
    }
    return requiredHalls;
}

int main() {
    int n;
    cin >> n;

    int* startTime = new int[n];
    int* endTime = new int[n];

    for(int i = 0; i < n; ++i) {
        cin >> startTime[i];
        cin >> endTime[i];
    }

    cout << requiredPartyHalls(n,startTime,endTime) << endl;
    return 0;
}
