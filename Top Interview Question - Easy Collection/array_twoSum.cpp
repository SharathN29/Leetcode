#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

vector<int> twoSum(vector<int>& nums, int target){
    unordered_map<int, int> umap;
    vector<int> res; 

    for(unsigned i = 0; i < nums.size(); i++){
        int add = target - nums[i];
        if(umap.find(add) != umap.end()){
            res.push_back(umap[add]);
            res.push_back(i);

            return res;
        }
        umap[nums[i]] = i;
    }
    return {};
}

int main(){
    vector<int> nums = {2, 7, 11, 15};
    int target = 18;

    vector<int> res = twoSum(nums, target);

    cout<<"Indicies of the two numbers are " << endl;
    for(int i = 0; i < res.size(); i++)
        cout<<res[i] << " ";
    cout<<"\n";
}