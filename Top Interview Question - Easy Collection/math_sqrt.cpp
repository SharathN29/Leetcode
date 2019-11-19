#include <iostream>
#include <cmath>

using namespace std; 

int mySqrt(int x) {
    long int r = x;
    while(r * r > x) 
        r = (r + x/r) / 2;
    return r;
}

int main() {
    int x = 36;
    int res = mySqrt(x);
    cout << "The Sqrt of " << x << " is " << mySqrt(x) << endl;
}