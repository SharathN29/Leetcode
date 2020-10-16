// https://leetcode.com/problems/hand-of-straights/

class Solution {
    public boolean isNStraightHand(int[] hand, int W) {
        if (hand.length % W != 0) {
            return false;
        }
        
        TreeMap<Integer, Integer> cardCount = new TreeMap();
        for (int card : hand) {
            cardCount.put(card, cardCount.getOrDefault(card, 0) + 1);
        }
        
        while (cardCount.size() > 0) {
            int minval = cardCount.firstKey();
            for (int card = minval; card < minval + W; card++) {
                if (!cardCount.containsKey(card)) {
                    return false;
                }
                cardCount.put(card, cardCount.get(card) - 1);
                if (cardCount.get(card) == 0) {
                    cardCount.remove(card);
                }
            }
        }
        return true; 
    }
}