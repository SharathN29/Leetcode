// https://leetcode.com/problems/word-ladder/

class Solution {
    public int ladderLength(String beginWord, String endWord, List<String> wordList) {
        Set<String> list = new HashSet<>(wordList);
        Queue<String> q = new LinkedList();
        q.add(beginWord);
        int dist = 1; 
        
        while (!q.isEmpty()) {
            int len = q.size();
            for (int i = 0; i < len; i++) {
                String word = q.poll();
                if (word.equals(endWord)) return dist;
                list.remove(word);
                
                char[] wordChar = word.toCharArray();
                
                for (int j = 0; j < wordChar.length; j++) {
                    char c = wordChar[j];
                    for (char ch = 'a'; ch <= 'z'; ch++) {
                        wordChar[j] = ch;
                        if (list.contains(String.valueOf(wordChar))) {
                            q.add(String.valueOf(wordChar));
                        }
                    }
                    wordChar[j] = c;
                }
            }
            dist++;
        }
        return 0;
    }
}