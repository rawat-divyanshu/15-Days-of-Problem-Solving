#include <iostream>
using namespace std;

void multiply(int* a, int &numDigit, int num) {
    int carry = 0;
    for(int i = 0; i < numDigit; ++i) {
        int product = a[i]*num + carry;
        a[i] = product % 10;
        carry = product / 10;
    }

    while(carry) {
        a[numDigit] = carry % 10;
        carry = carry / 10;
        ++numDigit;
    }
}

void big_factorial(int n) {
    int* a = new int[1000];

    for(int i = 0; i < 1000; ++i)
        a[i] = 0;

    a[0] = 1;
    int numDigit = 1;
    for(int i = 2; i <= n; ++i) {
        multiply(a,numDigit,i);
    }

    for(int i = numDigit-1; i >= 0; --i)
        cout << a[i];

    delete [] a;
    return;
}

int main() {
    int n;
    cin >> n;
    big_factorial(n);
    return 0;
}
