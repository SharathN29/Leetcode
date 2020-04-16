// https://leetcode.com/problems/reverse-integer/
// Time : O(log x), Space : O(1)

#include <iostream>

using namespace std;

int reverse(int x) {
    long res = 0;
    while(x) {
        res = res * 10 + x%10;
        x /= 10;
    }
    return (res < INT_MIN || res > INT_MAX) ? 0 : res;
}

int main() {
    cout << reverse(-123) << endl;
}