// https://leetcode.com/problems/unique-email-addresses/

class Solution {
    public int numUniqueEmails(String[] emails) {
        Set<String> uniqueEmails = new HashSet();
        for (String email : emails) {
            int i = email.indexOf('@');
            String local = email.substring(0, i);
            String rest = email.substring(i);
            if (local.contains("+")) {
                local = local.substring(0, local.indexOf('+'));
            }
            local = local.replaceAll("\\.", "");
            uniqueEmails.add(local + rest);
        }
        return uniqueEmails.size();
    }
}