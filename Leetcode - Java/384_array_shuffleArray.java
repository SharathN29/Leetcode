// https://leetcode.com/problems/shuffle-an-array/

class Solution {
    
    private int[] array; 
    private int[] original; 
    
    Random rand = new Random();

    public Solution(int[] nums) {
        array = nums;
        original = nums.clone();
    }
    
    /** Resets the array to its original configuration and return it. */
    public int[] reset() {
        array = original; 
        original = original.clone();
        return original; 
    }
    
    /** Returns a random shuffling of the array. */
    public int[] shuffle() {
        for (int i = 0; i < array.length; i++) {
            swapAt(i, randRange(i, array.length));
        }
        return array;
    }
    
    private int randRange(int min, int max) {
        return rand.nextInt(max - min) + min;
    }
    
    private void swapAt(int i, int j) {
        int temp = array[i];
        array[i] = array[j];
        array[j] = temp;
    }
}

/**
 * Your Solution object will be instantiated and called as such:
 * Solution obj = new Solution(nums);
 * int[] param_1 = obj.reset();
 * int[] param_2 = obj.shuffle();
 */