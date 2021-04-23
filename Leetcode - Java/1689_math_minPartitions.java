// https://leetcode.com/problems/partitioning-into-minimum-number-of-deci-binary-numbers/

class Solution {
    public int minPartitions(String n) {
        int partitions = 0;
        for (char c : n.toCharArray()) {
            partitions = Math.max(partitions, c - '0');
        }
        return partitions;
    }
}