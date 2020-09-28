class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int size = nums.size();
		if (size == 0 || k == 0)
			return 0;

		int count = 0, left = 0;
        int currProduct = 1;
        for (int right = 0; right < size; right++) {
            currProduct *= nums[right];
            // Shrink window on left side as long as the product of the subarray is greater than k
            while (left < right && currProduct >= k)
                currProduct /= nums[left++];

            if (currProduct < k)
                count += right - left + 1;
        }
		return count;
    }
};
 
