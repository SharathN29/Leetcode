#include <iostream> 
#include <unordered_map>
#include <vector>

using namespace std;

vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
    unordered_map<int, int> map;
    vector<int> res; 

    for(int i = 0; i < nums1.size(); i++)
        map[nums1[i]]++;

    for(int j = 0; j < nums2.size(); j++){
        if(map[nums2[j]]-- > 0)
            res.push_back(nums2[j]);
    }
    return res;
}

int main(){
    vector<int> num1 = {4,9,5}, num2 = {9,4,9,8,4};
    vector<int> res = intersect(num1, num2);
    for(int i = 0; i < res.size(); i++)
        cout<<res[i] << " ";
}