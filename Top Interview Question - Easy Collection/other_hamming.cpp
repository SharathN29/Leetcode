#include <iostream>

using namespace std;

int hammingDistance(int x, int y) {
    int diff = 0;
    string x1 = bitset<32>(x).to_string(); 
    string y1 = bitset<32>(y).to_string();

    for(int i = 0; i < x1.size() && i < y1.size(); i++){
        if(x1[i] != y1[i])
            diff++;
    }
    return diff; 
}

int main() {
    int x = 1577962638;
    int y = 1727613287;
    int res = hammingDistance(x, y);
    cout << "Hamming Distance " << res << endl;
}