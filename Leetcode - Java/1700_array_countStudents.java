// https://leetcode.com/problems/number-of-students-unable-to-eat-lunch/

class Solution {
    public int countStudents(int[] students, int[] sandwiches) {
        Queue<Integer> studentQueue = new LinkedList<>();
        for (int student : students) {
            studentQueue.offer(student);
        }
        int i = 0, count = 0;
        
        while (!studentQueue.isEmpty() && count != studentQueue.size()) {
            if (studentQueue.peek() == sandwiches[i]) {
                studentQueue.poll();
                count = 0;
                i++;
            } else {
                studentQueue.offer(studentQueue.poll());
                count++;
            }
        }
        return count;
    } 
}