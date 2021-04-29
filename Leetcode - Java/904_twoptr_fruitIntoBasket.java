// https://leetcode.com/problems/fruit-into-baskets/

class Solution {
    public int totalFruit(int[] tree) {
        int start = 0, maxlen = 0;
        Map<Integer, Integer> fruitMap = new HashMap();
        for (int end = 0; end < tree.length; end++) {
            fruitMap.put(tree[end], fruitMap.getOrDefault(tree[end], 0) + 1);
            while (fruitMap.size() > 2) {
                fruitMap.put(tree[start], fruitMap.get(tree[start]) - 1);
                if (fruitMap.get(tree[start]) == 0) {
                    fruitMap.remove(tree[start]);
                }
                start++;
            }
            maxlen = Math.max(maxlen, end - start + 1);
        }
        return maxlen;
    }
}
