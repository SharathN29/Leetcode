#include <iostream>

using namespace std;

bool isPowerOfThree(int n) {
    if(n < 1)
        return false;

    while(n % 3 == 0)
        n /= 3;
    
    return n == 1;
}

int main() {
    int n = 27;
    if(isPowerOfThree(n))
        cout<<"The number is a power of three" << endl;
    else cout << "The number is not a power of three " << endl;
}