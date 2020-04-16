// https://leetcode.com/problems/longest-substring-without-repeating-characters/

class Solution {
	public int lengthOfLongestSubstring(String s) {
		int start = -1, maxlen = 0;
		Map<Character, Integer> charMap = new HashMap<Character, Integer>();

		for(int i = 0; i < s.length(); i++) {
			if(charMap.containsKey(s.charAt(i)))
				start = Math.max(start, charMap.get(s.charAt(i)));
			charMap.put(s.charAt(i), i);
			maxlen = Math.max(maxlen, i-start);
		}
		return maxlen;
	}
}