class Solution {
public:
    int dfs(int r, int c, vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();

        if (r < 0 || r >= rows ||
            c < 0 || c >= cols ||
            grid[r][c] == 0)
        {
            return 0;
        }

        grid[r][c] = 0; // mark visited

        return 1 +
               dfs(r + 1, c, grid) +
               dfs(r - 1, c, grid) +
               dfs(r, c + 1, grid) +
               dfs(r, c - 1, grid);
    }

    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int maxArea = 0;

        for (int r = 0; r < grid.size(); r++) {
            for (int c = 0; c < grid[0].size(); c++) {
                if (grid[r][c] == 1) {
                    maxArea = max(maxArea, dfs(r, c, grid));
                }
            }
        }

        return maxArea;
    }
};