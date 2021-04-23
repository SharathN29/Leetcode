// https://leetcode.com/problems/time-based-key-value-store/

class TimeMap {
    
    Map<String, TreeMap> m;
    /** Initialize your data structure here. */
    public TimeMap() {
        m = new HashMap();
    }
    
    public void set(String key, String value, int timestamp) {
        if (!m.containsKey(key)) {
            m.put(key, new TreeMap());
        }
        m.get(key).put(timestamp, value);
    }
    
    public String get(String key, int timestamp) {
        if (!m.containsKey(key)) return "";
        TreeMap<Integer, String> tree = m.get(key);
        Integer t = tree.floorKey(timestamp);
        return t != null ? tree.get(t) : "";
    }
}

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap obj = new TimeMap();
 * obj.set(key,value,timestamp);
 * String param_2 = obj.get(key,timestamp);
 */