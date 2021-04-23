// https://leetcode.com/problems/distribute-candies/

class Solution {
    public int distributeCandies(int[] candyType) {
        int numCandies = candyType.length;
        Set<Integer> uniqueCandies = new HashSet();
        
        for (int candy : candyType) {
            uniqueCandies.add(candy);
        }
        
        return Math.min(numCandies/2, uniqueCandies.size());
    }
    
    // public int distributeCandies(int[] candies) {
    //     return Math.min(candies.length / 2, ((int) Arrays.stream(candies).distinct().count()));
    // }
}