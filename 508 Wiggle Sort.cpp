class Solution {
public:
    /**
     * @param nums a list of integer
     * @return void
     */
    void wiggleSort(vector<int>& nums) {
        // Write your code here
        for (int i = 1; i < nums.size(); i += 1) {
            if (   (i % 2 == 0 && nums[i - 1] < nums[i])
                || (i % 2 == 1 && nums[i - 1] > nums[i])   ) {
                swap(nums[i], nums[i - 1]);
            }
        }
    }
};
