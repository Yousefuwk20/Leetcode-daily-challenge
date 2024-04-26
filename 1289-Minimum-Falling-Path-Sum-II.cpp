class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& grid) {
        int n = grid.size();
        if (n == 1)
            return grid[0][0];

        vector<int> l(n);
        vector<int> r(n);

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                int d = INT_MAX;
                if (j > 0) d = min(d, l[j - 1]);
                if (j < n - 1) d = min(d, r[j + 1]);
                grid[i][j] += d;
            }

            l[0] = grid[i][0];
            for (int j = 1; j < n; j++)
                l[j] = min(l[j - 1], grid[i][j]);

            r[n - 1] = grid[i][n - 1];
            for (int j = n - 2; j >= 0; j--)
                r[j] = min(r[j + 1], grid[i][j]);
        }

        return l[n - 1];
    }
};