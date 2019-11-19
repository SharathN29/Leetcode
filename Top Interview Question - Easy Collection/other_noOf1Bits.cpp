#include <iostream>

using namespace std;

int hammingWeight(uint32_t n) {
    return n ? 1 + hammingWeight(n & (n-1)) : 0;
}

int main() {
    uint32_t n = 00000000000000000000000000001011;
    int weight = hammingWeight(n);
    cout <<"Number of 1's in the given unsigned integer is " << weight << endl;
}