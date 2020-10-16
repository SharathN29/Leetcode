// https://leetcode.com/problems/find-the-winner-of-an-array-game/

class Solution {
    public int getWinner(int[] arr, int k) {
        int curr = arr[0], winner = 0;
        for (int i = 1; i < arr.length; i++) {
            if (arr[i] > curr) {
                curr = arr[i];
                winner = 0;
            }
            if (++winner == k) break;
        }
        return curr;
    }
}