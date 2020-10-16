// https://leetcode.com/problems/search-suggestions-system/

class Solution {
    public List<List<String>> suggestedProducts(String[] products, String searchWord) {
        List<List<String>> suggestions = new ArrayList(); 
        PriorityQueue<String> heap = new PriorityQueue<>(Comparator.reverseOrder());
        
        for (int i = 1; i <= searchWord.length(); i++) {
            String currentSubstr = searchWord.substring(0, i);
            for (String product : products) {
                if (product.startsWith(currentSubstr)) {
                    heap.offer(product);
                }
                if (heap.size() > 3) {
                    heap.poll();
                }
            }
            
            LinkedList<String> tempList = new LinkedList<>();
            while (!heap.isEmpty()) {
                tempList.addFirst(heap.poll());
            }
            suggestions.add(tempList);
        }
        return suggestions;
    }
}