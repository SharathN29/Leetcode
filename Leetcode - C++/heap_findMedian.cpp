#include <iostream> 
#include <vector>
#include <queue>

using namespace std;

class MedianFinder {
private:
    priority_queue<int> first;
    priority_queue<int, vector<int>, greater<int>> second;

public:
    /** initialize your data structure here. */
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        if(first.empty() || (first.top() > num)) {
            first.push(num);
        } else {
            second.push(num);
        }

        if(first.size() > (second.size()+1)) {
            second.push(first.top());
            first.pop();
        }
        else if((first.size()+1) < second.size()) {
            first.push(second.top());
            second.pop();
        }
    }
    
    double findMedian() {
        if(first.size() == second.size()) {
            return first.empty() ? 0 : (first.top()+second.top())/2.0;
        } else {
            return first.size() > second.size() ? first.top() : second.top();
        }
    }
};