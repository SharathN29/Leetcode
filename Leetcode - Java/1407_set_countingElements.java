class Solution {
    public int countElements(int[] arr) {
        Set<Integer> s = new HashSet<Integer>();
        for(int n : arr) {
            s.add(n);
        }
        int count = 0;
        for(int n : arr) {
            if(s.contains(n+1)) {
                count++;
            }
        }
        return count; 
    }
}