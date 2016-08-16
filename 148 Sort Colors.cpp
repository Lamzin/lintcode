class Solution{
public:
    /**
     * @param nums: A list of integer which is 0, 1 or 2
     * @return: nothing
     */
    void sortColors(vector<int> &nums) {
        // write your code here
        int count[3] = {0, 0, 0};
        for (int i = 0; i < nums.size(); i++) {
            count[nums[i]]++;
        }
        int index = 0;
        for (int i = 0; i < 3; i++) {
            while(count[i]--) {
                nums[index++] = i;
            }
        }
    }
};
