// Reverse String 

// Write a function that reverses a string. The input string is given as an array of characters char[].
// Do not allocate extra space for another array, you must do this by modifying the input array in-place with O(1) extra memory.
// You may assume all the characters consist of printable ascii characters.

// Example 1:

// Input: ["h","e","l","l","o"]
// Output: ["o","l","l","e","h"]
// Example 2:

// Input: ["H","a","n","n","a","h"]
// Output: ["h","a","n","n","a","H"]


#include <iostream>
#include <string>

using namespace std;

void reverseString(vector<char>& s) {
    int i = 0, j = s.size() - 1;
    while(i < j){
        swap(s[i++], s[j--]);
    }
    cout<<"String after reversing " << endl;
    for(int i = 0; i < s.size(); i++)
        cout<<s[i];
    cout<<"\n";
}

int main() {
    vector<char> s = {"h", "e", "l", "l", "o"};
    reverseString(s);

}