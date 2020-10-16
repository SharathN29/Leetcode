// https://leetcode.com/problems/word-search/

class Solution {
    public boolean exist(char[][] board, String word) {
        for (int i = 0; i < board.length; i++) {
            for (int j = 0; j < board[i].length; j++) {
                if (exists(board, i, j, word, 0)) 
                    return true;
            }
        }
        return false;
    }
    
    private boolean exists(char[][] board, int i, int j, String word, int index) {
        if (index == word.length()) 
            return true; 
        
        if (i > board.length - 1 || i < 0 || j > board[0].length - 1 || j < 0 
            || board[i][j] != word.charAt(index))
            return false;
        
        board[i][j] = '*';
        boolean res = exists(board, i - 1, j, word, index + 1) ||
                      exists(board, i + 1, j, word, index + 1) ||
                      exists(board, i, j - 1, word, index + 1) ||
                      exists(board, i, j + 1, word, index + 1);
        board[i][j] = word.charAt(index);
        
        return res;
    }
}