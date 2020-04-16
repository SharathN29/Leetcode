// https://leetcode.com/problems/spiral-matrix/

class Solution {
    public List<Integer> spiralOrder(int[][] matrix) {
        List<Integer> list = new ArrayList<Integer>();
        int m = matrix.length;
        if(m == 0) return list;
        int n = matrix[0].length;
        int u = 0, d = m-1, l = 0, r = n-1;
        int index = 0;
        
        while(u <= d && l <= r) {
            for(int col = l; col <= r; col++) 
                list.add(index++, matrix[u][col]);
            
            if(++u > d) break;
            
            for(int row = u; row <= d; row++) 
                list.add(index++, matrix[row][r]);
            
            if(--r < l) break;
            
            for(int col = r; col >= l; col--)
                list.add(index++, matrix[d][col]);
            
            if(--d < u) break;
            
            for(int row = d; row >= u; row--) 
                list.add(index++, matrix[row][l]);
            
            if(++l > r) break;
        }
        return list;
    }
}