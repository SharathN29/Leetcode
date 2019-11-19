// Reverse Integer 

// Given a 32-bit signed integer, reverse digits of an integer.

// Example 1:

// Input: 123
// Output: 321
// Example 2:

// Input: -123
// Output: -321
// Example 3:

// Input: 120
// Output: 21
// Note:
// Assume we are dealing with an environment which could only store integers 
// within the 32-bit signed integer range: [−231,  231 − 1]. For the purpose of this problem, 
// assume that your function returns 0 when the reversed integer overflows.

#include <iostream>
#include <string>

using namespace std;

int reverse(int x){
    long int sum = 0, rem = 0;
    while(x) {
        sum = sum * 10 + x % 10;
        x /= 10;
    }
    return (sum<INT_MIN || sum>INT_MAX) ? 0 : sum;
}

int main(){
    int x = -112;
    int res = reverse(x);
    cout<<"Reversed number " << res << endl;
}