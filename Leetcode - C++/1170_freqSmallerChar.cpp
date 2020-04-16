//https://leetcode.com/problems/compare-strings-by-frequency-of-the-smallest-character/

#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std; 

int countFreq(string s) {
    vector<int> arr(26);
    for(char c: s)
        arr[c-'a']++;
    for(int i = 0; i < 26; i++){
        if(arr[i] != 0)
            return arr[i];
    }
    return 0;
}

vector<int> numSmallerByFrequency(vector<string>& queries, vector<string>& words) {
    vector<int> qCount;
    for(int i = 0; i < queries.size(); i++)
        qCount.push_back(countFreq(queries[i]));

    vector<int> wCount;
    for(int i = 0; i < words.size(); i++)
        wCount.push_back(countFreq(words[i]));
    sort(wCount.begin(), wCount.end());

    vector<int> res;
    for(int i = 0; i < qCount.size(); i++){
        int start = 0, end = wCount.size()-1;
        while(start <= end){
            int mid = (start + end)/2;
            if(wCount[mid] <= qCount[i])
                start = mid + 1;
            else end = mid-1;
        }
        res.push_back(wCount.size()-start);
    }
    return res;
}

int main() {
    vector<string> queries = {"bbb","cc"};
    vector<string> words = {"a","aa","aaa","aaaa"};
    vector<int> res = numSmallerByFrequency(queries, words);
    for(int i = 0; i < res.size(); i++) 
        cout << res[i] << " ";
    cout << endl;
}