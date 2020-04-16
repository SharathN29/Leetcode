// https://leetcode.com/problems/divide-two-integers/

#include <iostream>

using namespace std; 

class Solution {
public:
    // int divide(int dividend, int divisor) {
    //     if(dividend == INT_MAX && divisor == -1) 
    //         return INT_MAX;

    //     long dvd = labs(dividend), dvs = labs(divisor), ans = 0;
    //     int sign = dividend > 0 ^ divisor > 0 ? -1 : 1;
    //     while(dvd >= dvs) {
    //         long temp = dvs, m = 1;
    //         while(temp << 1 <= dvd) {
    //             temp <<= 1;
    //             m <<= 1;
    //         }
    //         dvd -= temp;
    //         ans += m;
    //     }
    //     return ans*sign;
    // }

    int divide(int A, int B) {
        if(A == INT_MIN && B == -1) return INT_MAX;
        int a = abs(A), b = abs(B), res = 0;
        while(a-b >= 0) {
            int x = 0;
            while(a - (b << x << 1) >= 0){
                x++;
            }
            res += 1 << x;
            a -= b << x;
        }
        return (A > 0) == (B > 0) ? res : -res;
    }
};

int main() {
    Solution *solution = new Solution();
    int dividend = 15, divisor = 3;
    int res = solution->divide(dividend, divisor);
    cout << "Result : " << res << endl;
}