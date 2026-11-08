class Solution {
public:
    int countServers(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<int> rowCnt(m, 0);
        vector<int> colCnt(n, 0);
        int cnt = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j]) {
                    rowCnt[i]++;
                    colCnt[j]++;
                }
            }
        }

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j]) {
                    if (rowCnt[i] - 1 || colCnt[j] - 1)
                        cnt++;
                }
            }
        }
        return cnt;
    }
};