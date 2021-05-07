// https://leetcode.com/problems/count-items-matching-a-rule/

class Solution {
    public int countMatches(List<List<String>> items, String ruleKey, String ruleValue) {
        int totalMatches = 0;
        
        for (int i = 0; i < items.size(); i++) {
            List<String> currItem = items.get(i);
            if (ruleKey.equals("type") && currItem.get(0).equals(ruleValue)) totalMatches++;
            else if (ruleKey.equals("color") && currItem.get(1).equals(ruleValue)) totalMatches++;
            else if (ruleKey.equals("name") && currItem.get(2).equals(ruleValue)) totalMatches++;
        }
        
        return totalMatches;
    }
}
