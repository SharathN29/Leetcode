// https://leetcode.com/problems/palindrome-partitioning/

class Solution {
    public List<List<String>> partition(String s) {
        List<List<String>> list = new ArrayList();
        backtrack(list, new ArrayList<>(), s, 0);
        return list;
    }
    
    private void backtrack(List<List<String>> list, List<String> templist, String s, int start) {
        if (start == s.length()) {
            list.add(new ArrayList<>(templist));
        } else {
            for (int i = start; i < s.length(); i++) {
                if (isPalindrome(s, start, i)) {
                    templist.add(s.substring(start, i + 1));
                    backtrack(list, templist, s, i + 1);
                    templist.remove(templist.size() - 1);
                }
            }
        }
    }
    
    private boolean isPalindrome(String s, int low, int high) {
        while (low < high) {
            if (s.charAt(low++) != s.charAt(high--)) return false;
        }
        return true;
    }
}