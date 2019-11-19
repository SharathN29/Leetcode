#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

int countPrimes(int n) {
    vector<bool> prime(n, true);
    prime[0] = false, prime[1] = false;
    for (int i = 0; i < sqrt(n); ++i) {
        if (prime[i]) {
            for (int j = i*i; j < n; j += i) {
                prime[j] = false;
            }    
        }    
    }
    return count(prime.begin(), prime.end(), true);
}

int main() {
    int n = 10;
    int res = countPrimes(n);
    cout << "Number of primes in the range 1 to " << n << " is " << res << endl;
}