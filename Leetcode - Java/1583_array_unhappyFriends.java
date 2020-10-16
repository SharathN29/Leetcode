// https://leetcode.com/problems/count-unhappy-friends/

class Solution {
    public int unhappyFriends(int n, int[][] preferences, int[][] pairs) {
        int res = 0;
        Map<Integer, Integer> map = buildHashMap(pairs);
        
        for (int[] pair : pairs) {
            if (isHappy(pair[0], pair[1], preferences, map) != -1) {
                res += 1;
            }
            
            if (isHappy(pair[1], pair[0], preferences, map) != -1) {
                res += 1;
            }
        }
        return res; 
    }
    
    public Map<Integer, Integer> buildHashMap(int[][] pairs) {
        Map<Integer, Integer> map = new HashMap();
        for (int[] pair : pairs) {
            map.put(pair[0], pair[1]);
            map.put(pair[1], pair[0]);
        }
        return map;
    }
    
    public int isHappy(int person, int currFriend, int[][] preferences, Map<Integer, Integer> map) {
        for (int friend : preferences[person]) {
            if (friend == currFriend) return -1;
            int friendsCurrFriend = map.get(friend);
            for (int friendsFriend : preferences[friend]) {
                if (friendsFriend == person) {
                    return friend;
                } else if (friendsFriend == friendsCurrFriend) {
                    break;
                }
            }
        }
        return -1;
    }
}