// Problem Link : https://www.spoj.com/problems/PRATA/

#include <iostream>
using namespace std;

int getOrderMaxTime(int orderedParatas, int totalCooks, int* cooks) {
    int minRankCook = cooks[0];

    for(int i = 1; i < totalCooks; ++i) {
        minRankCook = min(minRankCook,cooks[i]);
    }

    int maxTime = ((orderedParatas*(orderedParatas+1))/2)*minRankCook;
    return maxTime;
}

bool isPossibleToPrepareOrder(int orderedParatas, int totalCooks, int* cooks, int givenTime) {
    int preparedParatas = 0;

    for(int i = 0; i < totalCooks; ++i) {
        int currentCookParata = 0;
        int timeTaken = cooks[i];
        for(int j = 2; timeTaken <= givenTime; ++j) {
            ++currentCookParata;
            timeTaken += j*cooks[i];
        }
        preparedParatas += currentCookParata;
    }
    return orderedParatas <= preparedParatas;
}

int orderMinTime(int orderedParatas, int totalCooks, int* cooks) {

    int s = 0;
    int e = getOrderMaxTime(orderedParatas,totalCooks,cooks);

    int ans = e;

    while(s <= e) {
        int m = s + (e-s)/2;

        if(isPossibleToPrepareOrder(orderedParatas,totalCooks,cooks,m)) {
            ans = min(ans,m);
            e = m-1;
        } else {
            s = m+1;
        }
    }
    return ans;
}

int main() {
    int T;
    cin >> T;

    while(T--) {
        int orderedParatas;
        cin >> orderedParatas;

        int totalCooks;
        cin >> totalCooks;

        int* cooks = new int[totalCooks];

        for(int i = 0; i < totalCooks; i++) {
            cin >> cooks[i];
        }

        cout << orderMinTime(orderedParatas,totalCooks,cooks) << endl;
    }
    return 0;
}
