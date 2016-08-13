class Solution {
public:
    /**
     * @param grid a boolean 2D matrix
     * @return an integer
     */
    int numIslands(vector<vector<bool>>& grid) {
        // Write your code here
        int ans = 0;
        for (int i = 0; i < (int)grid.size(); i++) {
            for (int j = 0; j < (int)grid[i].size(); j++) {
                if (grid[i][j]) {
                    this->bfs(grid, i, j);
                    ans++;
                }
            }
        }
        return ans;
    }

    void bfs(vector<vector<bool>>& grid, int x, int y) {
            grid[x][y] = false;
            if (x + 1 < grid.size() && grid[x + 1][y]) {
                this->bfs(grid, x + 1, y);
            }
            if (x - 1 >= 0 && grid[x - 1][y]) {
                this->bfs(grid, x - 1, y);
            }
            if (y + 1 < grid[x].size() && grid[x][y + 1]) {
                this->bfs(grid, x, y + 1);
            }
            if (y - 1 >= 0 && grid[x][y - 1]) {
                this->bfs(grid, x, y - 1);
            }
        }
};
