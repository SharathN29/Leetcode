#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class MovingAverage {
private:
    queue<int> q;
    int maxSize;
    double sum;

public:
    /** Initialize your data structure here. */
    MovingAverage(int size) {
        maxSize = size;
        sum = 0.0;
    }
    
    double next(int val) {
        if(q.size() == maxSize) {
            sum -= q.front();
            q.pop();
        }
        q.push(val);
        sum += val;
        return sum/q.size();
    }
};