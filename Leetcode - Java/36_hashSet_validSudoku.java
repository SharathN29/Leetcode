// https://leetcode.com/problems/valid-sudoku/

class Solution {
	public boolean isValidSudoku(char[][] board) {
		Set<Character> rowVals = new HashSet<Character>();
		Set<Character> colVals = new HashSet<Character>();
		Set<Character> boxVals = new HashSet<Character>();

		for(int i = 0; i < 9; i++) {
			for(int j = 0; j < 9; j++) {
				if(board[i][j] != '.' && !rowVals.add(board[i][j])) return false; 
				if(board[j][i] != '.' && !colVals.add(board[j]i)) return false;
				int boxRow = 3 * (i/3) + (j/3);
				int boxCol = 3 * (i%3) + (j%3);
				if(board[boxRow][boxCol] != '.' && !boxVals[boxRow][boxCol]) return false;
			}
		}
		return true;
	}
}