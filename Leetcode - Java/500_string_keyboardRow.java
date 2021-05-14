// https://leetcode.com/problems/keyboard-row/

class Solution {
    public String[] findWords(String[] words) {
        List<String> res = new ArrayList<>();
        int[] charRows = {2, 3, 3, 2, 1, 2, 2, 2, 1, 2, 2, 2, 3, 3, 1, 1, 1, 1, 2, 1, 1, 3, 1, 3, 1, 3};
        
        for (String word : words) {
            res.add(word);
            word = word.toLowerCase();
            int firstCharRow = charRows[word.charAt(0) - 'a'];
            for (int i = 1; i < word.length(); i++) {
                int currCharRow = charRows[word.charAt(i) - 'a'];
                if (currCharRow != firstCharRow) {
                    res.remove(res.size() - 1);
                    break;
                }
            }
        }
        String[] wordsFromSingleRow = res.toArray(new String[0]);
        return wordsFromSingleRow;
    }
}