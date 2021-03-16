// An institute decided to give 100% scholarships to the needy students by taking an admission test.
// However in order to avoid any losses at the institute, they came up with a solution.
// institute has N students and M discount coupons. A student will get 100% waiver if he gets X discount coupons.
// However in order to get more discount coupons in addition to those M , Institute decided that some students who perform badly in the admission tests,
// need to pay additional amount equivalent to Y discount coupons, i.e. good students earn discount coupons and weak students need to pay coupons to get admission.
// Find out the maximum number of students who can get 100% waiver in their admission fees.
// Note : Institute will try his best to give 100% discount to maximum students possible.

// Input Format
// The first line contains 4 integers N M X Y

// Constraints
// 1 ≤ N,M,X,Y ≤ 10^9​​

// Output Format
// The output should contain a single integer representing the maximum number of students who can get 100% discount.

#include <iostream>
using namespace std;

bool isPossibleToGiveScholarship(long N, long M, long X, long Y, long studentCount) {
    long totalCoupons = M + Y*studentCount;
    return totalCoupons >= (N-studentCount)*X;
}

long findMaxScholarshipStudents(long N, long M, long X, long Y) {
	if(M/X == N) {
		return N;
	}
    long s = 0;
    long e = N;
    long ans = N;

    while(s <= e) {
        long m = s + (e-s)/2;

        if(isPossibleToGiveScholarship(N,M,X,Y,m)) {
            ans = min(ans,m);
            e = m-1;
        } else {
            s = m+1;
        }
    }
    return N - ans;
}

int main() {
    long N, M, X, Y;
    cin >> N >> M >> X >> Y;
    cout << findMaxScholarshipStudents(N,M,X,Y) << endl;
    return 0;
}
