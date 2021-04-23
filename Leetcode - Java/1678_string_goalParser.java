// https://leetcode.com/problems/goal-parser-interpretation/

class Solution {
    public String interpret(String command) {
        StringBuilder sb = new StringBuilder();
        for (int i = 0; i < command.length();) {
            if (command.substring(i, i+1).equals("G")) {
                sb.append("G");
                i++;
            }
            else if (command.substring(i, i+2).equals("()")) {
                sb.append("o");
                i += 2;
            } else if (command.substring(i, i+4).equals("(al)")) {
                sb.append("al");
                i += 4;
            }
        }
        return sb.toString();
    }
}