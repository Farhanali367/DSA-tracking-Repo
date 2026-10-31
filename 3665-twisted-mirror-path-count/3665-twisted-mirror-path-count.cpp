typedef long long ll;
class Solution {
public:
    int MOD = 1e9 + 7;
    vector<vector<ll>> dp;

    ll solveME(int i, int j, vector<vector<int>>& grid,
               vector<vector<pair<int, int>>>& dr,
               vector<vector<pair<int, int>>>& dd) {
        if (i == grid.size() - 1 && j == grid[0].size() - 1)
            return 1;

        if (dp[i][j] != -1)
            return dp[i][j];

        ll ans = 0;

        if (dr[i][j].first != -1) {
            auto [nxt_i, nxt_j] = dr[i][j];
            ans = (ans + solveME(nxt_i, nxt_j, grid, dr, dd)) % MOD;
        }
        if (dd[i][j].first != -1) {
            auto [nxt_i, nxt_j] = dd[i][j];
            ans = (ans + solveME(nxt_i, nxt_j, grid, dr, dd)) % MOD;
        }
        return dp[i][j] = ans;
    }

    int uniquePaths(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        dp.assign(m, vector<ll>(n, -1));
        vector<vector<pair<int, int>>> dr(m,
                                          vector<pair<int, int>>(n, {-1, -1}));
        vector<vector<pair<int, int>>> dd(m,
                                          vector<pair<int, int>>(n, {-1, -1}));

        for (int i = m - 1; i >= 0; i--) {
            for (int j = n - 1; j >= 0; j--) {
                if (j + 1 < n) {
                    if (grid[i][j + 1] == 0) {
                        dr[i][j] = {i, j + 1};

                    } else {
                        dr[i][j] = dd[i][j + 1];
                    }
                }

                if (i + 1 < m) {
                    if (grid[i + 1][j] == 0) {
                        dd[i][j] = {i + 1, j};
                    } else {
                        dd[i][j] = dr[i + 1][j];
                    }
                }
            }
        }

        return solveME(0, 0, grid, dr, dd);
    }
};