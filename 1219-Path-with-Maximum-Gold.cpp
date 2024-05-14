class Solution {
public:
    vector<int> roww = {1, -1, 0, 0};
    vector<int> coll = {0, 0, -1, 1};

    int backtrack(vector<vector<int>>& grid, vector<vector<int>>& vis, int x, int y, int n, int m) {
        if (x < 0 || x >= n || y < 0 || y >= m || grid[x][y] == 0 || vis[x][y]) return 0;

        vis[x][y] = 1;
        int maxGold = grid[x][y];

        for (int i = 0; i < 4; i++) {
            int newX = x + roww[i];
            int newY = y + coll[i];
            maxGold = max(maxGold, grid[x][y] + backtrack(grid, vis, newX, newY, n, m));
        }

        vis[x][y] = 0; 
        return maxGold;
    }

    int getMaximumGold(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        int maxGold = 0;
        vector<vector<int>> vis(n, vector<int>(m, 0));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] != 0) {
                    maxGold = max(maxGold, backtrack(grid, vis, i, j, n, m));
                }
            }
        }

        return maxGold;
    }
};