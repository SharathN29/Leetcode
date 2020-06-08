// https://leetcode.com/problems/first-bad-version/

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