// https://leetcode.com/problems/4sum/

class Solution {
	int len = 0;

    public List<List<Integer>> fourSum(int[] nums, int target) {
    	len = nums.length;
    	Arrays.sort(nums);
    	return ksum(nums, target, 4, 0);
    }

    private ArrayList<List<Integer>> ksum(int[] nums, int target, int k, int index) {
    	ArrayList<List<Integer>> res = new ArrayList<List<Integer>>();
    	if(index >= len) return res; 

    	if(k == 2) {
    		int i = index, j = len - 1;
    		while(i < j) {
    			if(nums[i] + nums[j] == target) {
    				List<Integer> tempList = new ArrayList<>();
    				tempList.add(nums[i]);
    				tempList.add(target-nums[i]);
    				res.add(tempList);

    				while(i < j && nums[i] == nums[i+1]) i++;
    				while(i < j && nums[j] == nums[j-1]) j--;
    				i++;
    				j--;
    			} else if(nums[i] + nums[j] < target) {
    				i++;
    			} else {
    				j--;
    			}
    		}
    	}

    	else {
    		for(int i = index; i < len - k + 1; i++) {
    			ArrayList<List<Integer>> temp = ksum(nums, target-nums[i], k-1, i+1);
    			if(temp != null) {
    				for(List<Integer> t : temp) 
    					t.add(0, nums[i]);
    				res.addAll(temp);
    			}
    			while(i < len-1 && nums[i] == nums[i+1]) i++;
    		}
    	}

    	return res;
    }
}