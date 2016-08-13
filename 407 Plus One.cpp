class Solution {
public:
    /**
     * @param digits a number represented as an array of digits
     * @return the result
     */
    vector<int> plusOne(vector<int>& digits) {
        // Write your code here
        int sum = 1;
        for (int i = digits.size() - 1; i >= 0; i--) {
            sum += digits[i];
            digits[i] = sum % 10;
            sum /= 10;
        }
        if (sum) {
            digits.push_back(0);
            for (int i = digits.size() - 1; i >= 1; i--) {
                digits[i] = digits[i - 1];
            }
            digits[0] = sum;
        }
        return digits;
    }
};
