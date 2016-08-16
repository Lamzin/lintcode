class Solution {
public:
    /**
     * @param costs n x 3 cost matrix
     * @return an integer, the minimum cost to paint all houses
     */
    int minCost(vector<vector<int>>& costs) {
        // Write your code here
        if (costs.size() == 0) {
            return 0;
        }

        int m;
        for (int i = 1; i < costs.size(); i++) {
            for (int j = 0; j < 3; j++) {
                m = 1000000009;
                for (int g = 0; g < 3; g++) {
                    if (j == g) {
                        continue;
                    }
                    m = min(m, costs[i - 1][g] + costs[i][j]);
                }
                costs[i][j] = m;
            }
        }

        return min(costs[costs.size() - 1][0], min(costs[costs.size() - 1][1], costs[costs.size() - 1][2]));
    }
};
