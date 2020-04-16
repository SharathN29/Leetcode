// https://leetcode.com/problems/fizz-buzz/

#include <iostream>
#include <vector>

using namespace std;

vector<string> fizzBuzz(int n) {
    vector<string> res; 
    for(int i = 1; i <= n; i++ ){
        if(i % 3 ==0 && i % 5 == 0)
            res.push_back("FizzBuzz");
        else if(i % 3 == 0)
            res.push_back("Fizz");
        else if(i % 5 == 0)
            res.push_back("Buzz");
        else res.push_back(to_string(i));
    } 
    return res;
}

int main() {
    int n = 10;
    vector<string> res = fizzBuzz(n);
    for(int i = 0; i < res.size(); i++){
        cout << res[i] << " ";
    }
    cout << endl;
}