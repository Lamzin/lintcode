class Solution {
public:
    /**
     * @param A, B: Two strings.
     * @return: The length of longest common subsequence of A and B.
     */
    int longestCommonSubsequence(string A, string B) {
        // write your code here
        if (A.length() == 0 || B.length() == 0) return 0;

        vector<vector<int>> dp(A.length(), vector<int>(B.length(), 0));

        int mx;
        for (int i = 0; i < A.length(); i++) {
            for (int j = 0; j < B.length(); j++) {
                mx = A[i] == B[j];
                if (i) mx = max(mx, dp[i - 1][j]);
                if (j) mx = max(mx, dp[i][j - 1]);
                if (i && j) mx = max(mx, dp[i - 1][j - 1] + (A[i] == B[j]));
                dp[i][j] = mx;
            }
        }
        return dp[A.length() - 1][B.length() - 1];
    }
};
