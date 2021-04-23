// https://leetcode.com/explore/challenge/card/june-leetcoding-challenge/540/week-2-june-8th-june-14th/3359/

class Solution {
  HashMap<Integer, List<Integer>> _eds = new HashMap<Integer, List<Integer>>();
  int [] _nums = {};

  private List<Integer> EDS(Integer i) {
    if (this._eds.containsKey(i)) return this._eds.get(i);
      
    List<Integer> maxSubset = new ArrayList();
    for (int k = 0; k < i; ++k) {
      if (this._nums[i] % this._nums[k] == 0) {
        List<Integer> subset = EDS(k);
        if (maxSubset.size() < subset.size()) maxSubset = subset;
      }    
    }

    List<Integer> newEntry = new ArrayList();
    newEntry.addAll(maxSubset);
    newEntry.add(this._nums[i]);

    this._eds.put(i, newEntry);
    return newEntry;
  }

  public List<Integer> largestDivisibleSubset(int[] nums) {
    int n = nums.length;
    if (n == 0) return new ArrayList();

    this._eds = new HashMap<Integer, List<Integer>>();

    Arrays.sort(nums);
    this._nums = nums;
    
    List<Integer> maxSubset = new ArrayList();    
    for (int i = 0; i < n; ++i) {
      List<Integer> subset = EDS(i);
      if (maxSubset.size() < subset.size()) maxSubset = subset;
    }

    return maxSubset;
  }
}