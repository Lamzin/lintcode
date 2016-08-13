class Solution {
public:
    /**
     * @param heights: a vector of integers
     * @return: an integer
     */
    int maxArea(vector<int> &heights) {
        // write your code here
        int left = 0, right = heights.size() - 1, maxArea = 0, curArea;
        while (left < right) {
            curArea = min(heights[left], heights[right]) * (right - left);
            maxArea = max(maxArea, curArea);
            if (heights[left] < heights[right]) {
                left++;
            } else {
                right--;
            }
        }
        return maxArea;
    }
};
