class Solution {
public:
    /**
     * @param nums: A list of integers
     * @return: The majority number
     */
    int majorityNumber(vector<int> nums) {
        // write your code here
        sort(nums.begin(), nums.end());
        int count = 1;
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] == nums[i - 1]) {
                count++;
            } else {
                if (2 * count > nums.size()) {
                    return nums[i - 1];
                }
                count = 1;
            }
        }
        return nums[nums.size() - 1];
    }
};
