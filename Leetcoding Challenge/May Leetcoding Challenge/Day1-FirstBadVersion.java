// https://leetcode.com/explore/challenge/card/may-leetcoding-challenge/534/week-1-may-1st-may-7th/3316/

/* The isBadVersion API is defined in the parent class VersionControl.
      boolean isBadVersion(int version); */

public class Solution extends VersionControl {
    public int firstBadVersion(int n) {
        int low = 1, up = n, mid; 
        
        while(low < up) {
            mid = low + (up - low) / 2;
            if(!isBadVersion(mid))
                low = mid + 1;
            else up = mid;
        }
        return low;
    }
}