// https://leetcode.com/explore/challenge/card/30-day-leetcoding-challenge/531/week-4/3313/

class FirstUnique {

    private class ListNode {
        ListNode _prev;
        ListNode _next;
        int _val;
        
        public ListNode(int val) {
            _val = val;
            _next = null;
            _prev = null;
        }
    }
    
    private class MyDLL{
        private ListNode _head;
        private ListNode _tail;
        
        public MyDLL() {
            _head = new ListNode(-1);
            _tail = new ListNode(-1);
            
            _head._next = _tail;
            _tail._prev = _head; 
        }
        
        public ListNode getFirst() {
            return _head._next;
        }
        
        public boolean isEmpty() {
            return _head._next == _tail;
        }
        
        public void remove(ListNode node) {
            ListNode prev = node._prev;
            ListNode next = node._next;
            
            prev._next = next;
            next._prev = prev;
        }
        
        public ListNode insert(int num) {
            ListNode node = new ListNode(num);
            ListNode prev = _tail._prev;
            
            prev._next = node;
            node._next = _tail;
            _tail._prev = node;
            node._prev = prev;
            
            return node;
        }
    }
    
    private MyDLL _keys;
    private Map<Integer, ListNode> _map;
    
    public FirstUnique(int[] nums) {
        _map = new HashMap<>();
        _keys = new MyDLL();
        
        for(int n : nums) {
            add(n);
        }
    }
    
    public int showFirstUnique() {
        if(_keys.isEmpty())
            return -1;
        else return _keys.getFirst()._val;
    }
    
    public void add(int value) {
        if(_map.containsKey(value)) {
            if(_map.get(value) != null) {
                _keys.remove(_map.get(value));
                _map.put(value, null);
            }
        } else {
            ListNode node = _keys.insert(value);
            _map.put(value, node);
        }
    }
}

/**
 * Your FirstUnique object will be instantiated and called as such:
 * FirstUnique obj = new FirstUnique(nums);
 * int param_1 = obj.showFirstUnique();
 * obj.add(value);
 */