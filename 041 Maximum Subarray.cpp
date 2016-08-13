class Solution {
public:
    /**
     * @param nums: A list of integers
     * @return: A integer indicate the sum of max subarray
     */
    int maxSubArray(vector<int> nums) {
        // write your code here
        if (nums.size() == 0) {
            return 0;
        }

        int result = nums[0], current = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            if (current < 0) {
                current = 0;
            }
            current += nums[i];
            if (current > result) {
                result = current;
            }
        }
        return result;
    }
};
