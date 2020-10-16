// https://leetcode.com/problems/count-largest-group/

class Solution {
	public int countLargestGroup(int n) {
		int[] map = new int[37];
		int maxCount = 0, res = 0;
		for (int i = 1; i <= n; i++) {
			int num = i, sum = 0;
			while (num > 0) {
				sum += num %10;
				num/=10;
			}
			++map[sum];
			if (maxCount < map[sum]) {
				maxCount = map[sum];
				res = 1;
				} else if (maxCount == map[sum]) {
				res++;
			}
		}
		return res;
	}
}