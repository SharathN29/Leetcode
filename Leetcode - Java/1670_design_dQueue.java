// https://leetcode.com/problems/design-front-middle-back-queue/

class FrontMiddleBackQueue {
    Deque<Integer> left;
    Deque<Integer> right;
    
    public FrontMiddleBackQueue() {
        left = new ArrayDeque<>();
        right = new ArrayDeque<>();
    }
    
    public void pushFront(int val) {
        left.offerFirst(val);
        rebalance();
    }
    
    public void pushMiddle(int val) {
        left.offerLast(val);
        rebalance();
    }
    
    public void pushBack(int val) {
        right.offerLast(val);
        rebalance();
    }
    
    public int popFront() {
        int res = -1;
        if(!left.isEmpty()){
            res = left.pollFirst();
        }
        else if(!right.isEmpty()){
            res = right.pollFirst();
        }
        rebalance();
        return res;
    }
    
    public int popMiddle() {
        int res = -1;
        boolean isRight = (left.size()+right.size())%2==1;
        if(isRight && !right.isEmpty()){
            res = right.pollFirst();
        }
        else if(!left.isEmpty()){
            res = left.pollLast();
        }
        rebalance();
        return res;
    }
    
    public int popBack() {
        int res = -1;
        if(!right.isEmpty()){
            res = right.pollLast();
        }
        else if(!left.isEmpty()){
            res = left.pollLast();
        }
        rebalance();
        return res;
    }
    
    private void rebalance(){
        while(left.size()<right.size()-1){
            left.offerLast(right.pollFirst());
        }
        while(left.size()>right.size()){
            right.offerFirst(left.pollLast());
        }
    }
}

/**
 * Your FrontMiddleBackQueue object will be instantiated and called as such:
 * FrontMiddleBackQueue obj = new FrontMiddleBackQueue();
 * obj.pushFront(val);
 * obj.pushMiddle(val);
 * obj.pushBack(val);
 * int param_4 = obj.popFront();
 * int param_5 = obj.popMiddle();
 * int param_6 = obj.popBack();
 */