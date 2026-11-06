class Solution {
public:
    vector<int> countServers(int n, vector<vector<int>>& logs, int x,
                             vector<int>& queries) {
        int s = queries.size();
        vector<int> arr(s);
        sort(logs.begin(), logs.end(),
             [](auto& a, auto& b) { return a[1] < b[1]; });
        int m = logs.size();
        vector<pair<int, int>> sq;
        for (int i = 0; i < s; i++) {
            sq.push_back({queries[i], i});
        }
        sort(sq.begin(), sq.end());
        int l = 0;
        int r = 0;
        int active = 0;
        vector<int> freq(n + 1, 0);
        for (auto [en, idx] : sq) {
            int st = en - x;
            while (r < m && logs[r][1] <= en) {
                int id = logs[r][0];
                if (freq[id] == 0) {
                    active++;
                }
                freq[id]++;
                r++;
            }
            while (l < r && logs[l][1] < st) {
                int id = logs[l][0];
                freq[id]--;
                if (freq[id] == 0) {
                    active--;
                }
                l++;
            }
            arr[idx] = n - active;
        }
        return arr;
    }
};