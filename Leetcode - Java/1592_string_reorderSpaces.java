// https://leetcode.com/problems/rearrange-spaces-between-words/

class Solution {
    public String reorderSpaces(String text) {
        String[] words = text.trim().split("\\s+");
        int count = words.length; 
        int spaces = text.chars()
                        .map(c -> c == ' ' ? 1 : 0)
                        .sum();
        
        int gap = count <= 1 ? 0 : spaces / (count - 1);
        int trailingSpace = gap == 0 ? spaces : spaces % (count - 1);
        return String.join(" ".repeat(gap), words) + " ".repeat(trailingSpace);
    }
}