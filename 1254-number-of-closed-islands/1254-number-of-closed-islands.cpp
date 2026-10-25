class Solution {
public:
    vector<int> drow = {-1, 1, 0, 0};
    vector<int> dcol = {0, 0, 1, -1};

    bool dfs(int i, int j, int n, int m, vector<vector<int>>& grid,
             vector<vector<bool>>& vis) {
        
        vis[i][j] = true;
        bool isClosed = true;

        if(i == 0 || i == n - 1 || j == 0 || j == m - 1)
            isClosed = false;

        for (int x = 0; x < 4; x++) {
            int nrow = i + drow[x];
            int ncol = j + dcol[x];

            if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m &&
                !grid[nrow][ncol] && !vis[nrow][ncol]) {
                if (!dfs(nrow, ncol, n, m, grid, vis))
                    isClosed = false;
            }
        }
        return isClosed;
    }

    int closedIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<bool>> vis(n, vector<bool>(m, false));
        int cnt = 0;

        for (int i = 1; i < n - 1; i++) {
            for (int j = 1; j < m - 1; j++) {
                if (!grid[i][j] && !vis[i][j]) {
                    if (dfs(i, j, n, m, grid, vis)) cnt++;
                }
            }
        }

        return cnt;
    }
};