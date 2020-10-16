// https://leetcode.com/problems/alert-using-same-key-card-three-or-more-times-in-a-one-hour-period/

class Solution {
    public List<String> alertNames(String[] keyName, String[] keyTime) {
        Map<String, TreeSet<Integer>> entries = new HashMap<>();
        for (int i = 0; i < keyName.length; i++) {
            int time = Integer.parseInt(keyTime[i].substring(0, 2)) * 60 + Integer.parseInt(keyTime[i].substring(3));
            entries.computeIfAbsent(keyName[i], s -> new TreeSet<>()).add(time);
        }

        TreeSet<String> names = new TreeSet<>();
        for (Map.Entry<String, TreeSet<Integer>> e : entries.entrySet()) {
            List<Integer> times = new ArrayList<>(e.getValue());
            for (int low = 0, high = 1; high < times.size(); high++) {
                while (low < high && times.get(high) - times.get(low) > 60) {
                    low++;
                }
                if (high - low >= 2 && times.get(high) - times.get(low) <= 60) {
                    names.add(e.getKey());
                    break;
                }
            }
        }
        return new ArrayList<>(names);
    }
}