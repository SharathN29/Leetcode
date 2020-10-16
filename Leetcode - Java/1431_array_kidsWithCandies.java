// https://leetcode.com/problems/kids-with-the-greatest-number-of-candies/

class Solution {
    public List<Boolean> kidsWithCandies(int[] candies, int extraCandies) {
        int maxElem = Arrays.stream(candies).max().getAsInt();
        List<Boolean> res = new ArrayList<>();
        
        for(int candy : candies) 
            res.add(candy + extraCandies >= maxElem); 
        return res;
    }
}