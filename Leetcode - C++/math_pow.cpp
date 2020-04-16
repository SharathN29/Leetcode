// https://leetcode.com/problems/powx-n/
// Time : O(log n), Space : O(1)

#include <iostream>

using namespace std;

double myPow(double x, int n) {
    long int m = n;
    if(m == 0) return 1;
    if(m < 0) {
        m = -m;
        x = 1/x;
    }
    return (m % 2 == 0) ? myPow(x*x, m/2) : x * myPow(x*x, m/2);
}

int main() {
    double x = 2.100000;
    int n = 3;
    double res = myPow(x, n);
    cout << "Result : " << res << endl;
}