class Solution {
public:
    int dp[101][101][202];

    bool solve(int i, int j, int m, int n, int open,
               vector<vector<char>>& grid) {

        if (i >= m || j >= n)
            return false;

        if (open < 0)
            return false;

        if (grid[i][j] == '(')
            open++;
        else
            open--;

        if (open < 0)
            return false;

        if (i == m - 1 && j == n - 1)
            return open == 0;

        if (dp[i][j][open] != -1)
            return dp[i][j][open];

        bool down = solve(i + 1, j, m, n, open, grid);
        bool right = solve(i, j + 1, m, n, open, grid);

        return dp[i][j][open] = down || right;
    }

    bool hasValidPath(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        memset(dp, -1, sizeof(dp));

        return solve(0, 0, m, n, 0, grid);
    }
};