// https://leetcode.com/problems/determine-color-of-a-chessboard-square/

// class Solution {
//     public boolean squareIsWhite(String coordinates) {
//         char col = coordinates.charAt(0);
//         Set<Character> columns = new HashSet<>(Arrays.asList('a', 'c', 'e', 'g'));
//         if (columns.contains(col)) {
//             return Character.getNumericValue(coordinates.charAt(1)) % 2 == 0 ? true : false;
//         } else {
//             return Character.getNumericValue(coordinates.charAt(1)) % 2 == 0 ? false : true;
//         }
//     }
// }

class Solution {
    public boolean squareIsWhite(String coordinates) {
        int sumOfCoordinates = coordinates.charAt(0) - 'a' + coordinates.charAt(1) - '1';
        if(sumOfCoordinates % 2 == 0)
            return false;
        return true;
    }
}
