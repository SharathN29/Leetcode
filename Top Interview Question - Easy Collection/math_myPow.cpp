#include <iostream>

using namespace std; 

double myPow(double x, int n) {
    long int m = n;
    if(m == 0) return 1; 
    if(m < 0) {
        m = -m;
        x = 1/x;
    }
    return (m%2 == 0) ? myPow(x*x, n/2) : x * myPow(x*x, n/2);
}

int main() {
    double x = 2.1000;
    int n = 3;
    double res = myPow(x, n);
    cout << "Power of " << x << " over " << n << " is " << res << endl;
}