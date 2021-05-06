// https://leetcode.com/problems/find-winner-on-a-tic-tac-toe-game/

class Solution {
    public String tictactoe(int[][] moves) {
        int[] A = new int[8], B = new int[8];
        
        for (int i = 0; i < moves.length; i++) {
            int row = moves[i][0], col = moves[i][1];
            int[] currPlayer = (i % 2 == 0) ? A : B;
            
            currPlayer[row]++;
            currPlayer[col + 3]++;
            if (row == col) currPlayer[6]++;
            if (row == 2 - col) currPlayer[7]++;
        }
        
        for (int i = 0; i < 8; i++) {
            if (A[i] == 3) return "A";
            if (B[i] == 3) return "B";
        }
        
        return moves.length == 9 ? "Draw" : "Pending";
    }
}
