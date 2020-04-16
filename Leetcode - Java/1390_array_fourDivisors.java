// https://leetcode.com/problems/four-divisors/

class Solution {
	private int fourDivisors(int n) {
		int sum = 0;
		List<Integer> divisors = new ArrayList<>();
		for(int i = 1; i < Math.sqrt(n); i++) {
			if(n % i == 0) {
				if(n / i == i) {
					divisors.add(i);
				} else {
					divisors.add(i);
					divisors.add(n/i);
				}
			}
		}
		if(divisors.size() == 4){
			for(int div : divisors) 
				sum += div;
			return sum;
		} 
		return 0;
	}

    public int sumFourDivisors(int[] nums) {
    	int res = 0;
        for(int i = 0; i < nums.length; i++) {
        	res += fourDivisors(nums[i]);
        }
        return res; 
    }
}