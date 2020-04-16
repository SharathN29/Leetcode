// https://leetcode.com/problems/two-sum-iii-data-structure-design/

class TwoSum {
    Map<Integer, Integer> numCounts; 
    /** Initialize your data structure here. */
    public TwoSum() {
        this.numCounts = new HashMap<Integer, Integer>();
    }
    
    /** Add the number to an internal data structure.. */
    public void add(int number) {
        this.numCounts.put(number, this.numCounts.getOrDefault(number,0)+1);
    }
    
    /** Find if there exists any pair of numbers which sum is equal to the value. */
    public boolean find(int value) {
        for(Map.Entry<Integer, Integer> entry : numCounts.entrySet()) {
            int complement = value - entry.getKey();
            if(complement != entry.getKey()) {
                if(this.numCounts.containsKey(complement))
                    return true;
            } else {
                if(entry.getValue() > 1)
                    return true;
            }
        }
        return false; 
    }
}

/**
 * Your TwoSum object will be instantiated and called as such:
 * TwoSum obj = new TwoSum();
 * obj.add(number);
 * boolean param_2 = obj.find(value);
 */