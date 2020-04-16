// https://leetcode.com/problems/logger-rate-limiter/

class Logger {
    private HashMap<String, Integer> msg; 

    /** Initialize your data structure here. */
    public Logger() {
        msg = new HashMap<String, Integer>();
    }
    
    /** Returns true if the message should be printed in the given timestamp, otherwise returns false.
        If this method returns false, the message will not be printed.
        The timestamp is in seconds granularity. */
    public boolean shouldPrintMessage(int timestamp, String message) {
        if(!this.msg.containsKey(message)) {
            this.msg.put(message, timestamp);
            return true;
        }
        
        Integer oldTime = this.msg.get(message);
        if(timestamp - oldTime >= 10) {
            this.msg.put(message, timestamp);
            return true;
        } else 
            return false;
    }
}

/**
 * Your Logger object will be instantiated and called as such:
 * Logger obj = new Logger();
 * boolean param_1 = obj.shouldPrintMessage(timestamp,message);
 */