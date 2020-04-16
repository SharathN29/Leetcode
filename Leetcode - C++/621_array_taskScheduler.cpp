// https://leetcode.com/problems/task-scheduler/

#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>

using namespace std; 

struct compare {
    bool operator()(const int& a, const int& b) {
        return b > a;
    }
};

int leastInterval(vector<char>& tasks, int n) {
    unordered_map<char, int> map;
    for(char& c: tasks) 
        map[c]++;
    
    priority_queue<int, vector<int>, compare> pq;
    for(auto& it: map) {
        pq.push(it.second);
    }
    
    int cycles = 0;
    while(!pq.empty()) {
        vector<int> temp;
        for(int i = 0; i < n+1; i++) {
            if(!pq.empty()) {
                temp.push_back(pq.top());
                pq.pop();
            }
        }
        
        for(int i : temp) {
            if(--i > 0)
                pq.push(i);
        }
        
        cycles += pq.empty() ? temp.size() : n+1;
    }
    return cycles;
}

int main() {
    int n = 2;
    vector<char> tasks = {'A', 'A', 'A', 'B', 'B', 'B'};
    int cycles = leastInterval(tasks, n);
    cout << "Least Interval " << cycles << endl;
}