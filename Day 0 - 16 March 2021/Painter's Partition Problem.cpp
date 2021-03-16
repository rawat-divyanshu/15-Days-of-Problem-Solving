// Given K painters to paint N boards where each painter takes 1 unit of time to paint 1 unit of boards
// i.e. if the length of a particular board is 5, it will take 5 units of time to paint the board.
// Compute the minimum amount of time to paint all the boards.

// Note that:
// Every painter can paint only contiguous segments of boards.
// A board can only be painted by 1 painter at maximum.

// Input Format
// First line contains K which is the number of painters. Second line contains N which indicates the number of boards.
// Third line contains N space separated integers representing the length of each board.

// Constraints
// 1 <= K <= 10
// 1 <= N <= 10
// 1<= Length of each Board <= 10^8

// Output Format
// Output the minimum time required to paint the board.

#include <bits/stdc++.h>
using namespace std;

bool isPossibleToPaint(long K, long N, long* boards, long totalLength, long time) {
    long painterUsed = 1;
    long lengthPaintedByCurrentPainter = 0;
    for(long i = 0; i < N; ++i) {
        if(boards[i] > time) {
            return false;
        }
        if(lengthPaintedByCurrentPainter + boards[i] > time) {
            lengthPaintedByCurrentPainter = boards[i];
            ++painterUsed;
        } else {
            lengthPaintedByCurrentPainter += boards[i];
        }
    }
    return painterUsed == K;    
}

long minTimeToPaintBoards(long K, long N, long* boards) {
    long maxLength = INT_MIN, minLength = INT_MAX, totalLength = 0;
    for(long i = 0; i < N; ++i) {
        minLength = min(minLength,boards[i]);
        maxLength = max(maxLength,boards[i]);
        totalLength += boards[i];
    }
    if(K == N) {
        return maxLength;
    }
	if(K == 1) {
		return totalLength;
	}

    long s = maxLength;
    long e = totalLength;
    long ans = totalLength;

    while(s <= e) {
        long m = s + (e-s)/2;

        if(isPossibleToPaint(K,N,boards,totalLength,m)) {
            ans = min(ans,m);
            e = m-1;            
        } else {
            s = m+1;
        }
    }
    return ans;
}

int main() {
    long K,N;
    cin >> K >> N;

    long* boards = new long[N];

    for(long i = 0; i < N; ++i)
        cin >> boards[i];

    cout << minTimeToPaintBoards(K,N,boards) << endl;
    return 0;
}
