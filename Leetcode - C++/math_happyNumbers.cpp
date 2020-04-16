#include <iostream>

using namespace std;

int sumOfNum(int num) {
    int sum = 0, tmp;
    while (num) {
        tmp = num % 10;
        sum += tmp * tmp;
        num /= 10;
    }
    return sum;
}

bool isHappy(int n) {
    int slow, fast;
    slow= fast = n;
    do{
        slow = sumOfNum(slow);
        fast = sumOfNum(fast);
        fast = sumOfNum(fast);
        if(fast == 1) return true;
    } while(slow != fast);
    return false;

}

int main() {
    int n = 19;
    if(isHappy(n))
        cout << "Happy Numbers" << endl;
    else cout << "Unhappy numbers" << endl;
}