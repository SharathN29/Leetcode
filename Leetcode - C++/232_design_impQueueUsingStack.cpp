// https://leetcode.com/problems/implement-queue-using-stacks/

#include <iostream> 
#include <stack>

using namespace std; 

class MyQueue {
public:
    /** Initialize your data structure here. */
    MyQueue() {
        
    }
    
    /** Push element x to the back of queue. */
    void push(int x) {
        while(!s1.empty()) {
        	s2.push(s1.top());
        	s1.pop();
        }
        s1.push(x);
        while(!s2.empty()) {
        	s1.push(s2.top());
        	s2.pop();
        }
    }
    
    /** Removes the element from in front of queue and returns that element. */
    int pop() {
    	int rem = s1.top();
    	s1.pop();
        return rem;
    }
    
    /** Get the front element. */
    int peek() {
        return s1.top();
    }
    
    /** Returns whether the queue is empty. */
    bool empty() {
        return s1.empty();
    }

private:
	stack<int> s1, s2; 
};