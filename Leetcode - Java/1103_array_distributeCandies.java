// https://leetcode.com/problems/distribute-candies-to-people/

class Solution {
    public int[] distributeCandies(int candies, int num_people) {
        int[] res = new int[num_people];
        
        int index = 0, currCandie = 1;
        while (candies > currCandie) {  
            res[index % num_people] += currCandie;
            candies -= currCandie;
            currCandie++;
            index++;
        }
        res[index % num_people] += candies;
        return res;
    }
}