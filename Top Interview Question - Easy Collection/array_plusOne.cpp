#include <iostream>
#include <vector>

using namespace std;

vector<int> plusOne(vector<int>& digits) {
    for(int i = digits.size() - 1; i >= 0; i--){
        if(digits[i] == 9)
            digits[i] = 0;
        else{
            digits[i]++;
            return digits;
        }
    }    
    digits[0] = 1;
    digits.push_back(0);
    return digits;
}

int main(){
    vector<int> digits = {4,3,2,1};
    vector<int> res = plusOne(digits); 
    std::cout<<"Resultant vector " << endl;
    for(int i = 0; i < res.size(); i++)
        std::cout<<res[i] << " ";
    std::cout<<"\n";  
}