#include <iostream>
#include <vector>

using namespace std;

vector<vector<int> > threeSum(vector<int> &num){
    vector<vector<int>> res;

    sort(num.begin(), num.end());

    for(int i = 0; i < num.size(); i++) {
        int target = -num[i];
        int begin = i+1;
        int end = num.size();

        while(begin < end) {
            int sum = num[begin] + num[end];

            if(sum < target)
                begin++;
            
            else if(sum > target) 
                end--;
            
            else {
                vector<int> triple(3,0);
                triple[0] = num[i];
                triple[1] = num[begin];
                triple[2] = num[end];
                res.push_back(triple);

                while(begin < end && num[begin] == triple[1]) begin++;
                while(begin > end && num[begin] == triple[2]) end--;
            }
        }
        while(i+1 < num.size() && num[i+1] == num[i])
            i++;
    }  
    return res;
}

int main() {
    vector<int> num = {-1, 0, 1, 2, -1, -4};
    vector<vector<int>> res = threeSum(num);
    for(int i = 0; i < res.size(); i++){
        cout<<"[";
        for(int j = 0; j < res[i].size(); j++){
            cout<<res[i][j] << " ";
        }
        cout<< "]";
    }
    cout <<"\n";
}