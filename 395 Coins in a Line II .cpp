class Solution {
public:
    /**
     * @param values: a vector of integers
     * @return: a boolean which equals to true if the first player will win
     */
    bool firstWillWin(vector<int> &values) {
        // write your code here
        int sum = 0;
        for (int i = 0; i < values.size(); i++) {
            sum += values[i];
        }

        vector<vector<int>> dp(2, vector<int>(values.size(), 0));
        int maxValue = 0, maxLength = 0;
        int curValue = 0, curLength = 0;

        for (int i = (int)values.size() - 1; i >= 0; i--) {
            maxValue = values[i];
            maxLength = 1;
            if (i + 1 < (int)values.size() && i + dp[1][i + 1] + 1 < (int)values.size()) {
                maxValue += dp[0][i + dp[1][i + 1] + 1];
            }

            if (i + 1 < values.size()) {
                curValue = values[i] + values[i + 1];
                curLength = 2;
                if (i + 2 < (int)values.size() && i + dp[1][i + 2] + 2 < (int)values.size()) {
                    curValue += dp[0][i + dp[1][i + 2] + 2];
                }

                if (curValue > maxValue) {
                    maxValue = curValue;
                    maxLength = curLength;
                }
            }

            dp[0][i] = maxValue;
            dp[1][i] = maxLength;
        }

        return 2 * dp[0][0] > sum;
    }
};
