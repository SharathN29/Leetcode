// https://leetcode.com/problems/design-underground-system/

class UndergroundSystem {

    Map<Integer, Pair<String, Integer>> checkInMap = new HashMap();
    Map<String, Pair<Integer, Integer>> checkOutMap = new HashMap();

    public UndergroundSystem() {

    }

    public void checkIn(int id, String stationName, int t) {
        checkInMap.put(id, new Pair<>(stationName, t));
    }

    public void checkOut(int id, String stationName, int t) {
        Pair<String, Integer> checkin = checkInMap.get(id);
        String route = checkin.getKey() + "-" + stationName;
        int journeyTime = t - checkin.getValue();

        Pair<Integer, Integer> checkout = checkOutMap.getOrDefault(route, new Pair<>(0, 0));
        checkOutMap.put(route, new Pair<>(checkout.getKey() + journeyTime, checkout.getValue() + 1));
    }

    public double getAverageTime(String startStation, String endStation) {
        String route = startStation + "-" + endStation;
        Pair<Integer, Integer> checkout = checkOutMap.get(route);
        return (double) checkout.getKey() / checkout.getValue();
    }
}

/**
 * Your UndergroundSystem object will be instantiated and called as such:
 * UndergroundSystem obj = new UndergroundSystem();
 * obj.checkIn(id,stationName,t);
 * obj.checkOut(id,stationName,t);
 * double param_3 = obj.getAverageTime(startStation,endStation);
 */
