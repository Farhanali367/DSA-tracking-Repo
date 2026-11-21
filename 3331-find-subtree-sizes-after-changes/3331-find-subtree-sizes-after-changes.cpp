class Solution {
public:
    void dfs1(int node, vector<vector<int>>& adj, string& s,
              vector<int>& newParent, vector<int>& last) {

        int ch = s[node] - 'a';
        int prev = last[ch];

        if (prev != -1) {
            newParent[node] = prev;
        }

        last[ch] = node;

        for (int child : adj[node]) {
            dfs1(child, adj, s, newParent, last);
        }

        last[ch] = prev;
    }

    int dfs2(int node, vector<vector<int>>& adj, vector<int>& ans) {
        int size = 1;

        for (int child : adj[node]) {
            size += dfs2(child, adj, ans);
        }

        ans[node] = size;
        return size;
    }

    vector<int> findSubtreeSizes(vector<int>& parent, string s) {
        int n = s.size();

        vector<vector<int>> adj(n);

        for (int i = 1; i < n; i++) {
            adj[parent[i]].push_back(i);
        }

        vector<int> newParent = parent;
        vector<int> last(26, -1);

        dfs1(0, adj, s, newParent, last);

        vector<vector<int>> newAdj(n);

        for (int i = 1; i < n; i++) {
            newAdj[newParent[i]].push_back(i);
        }

        vector<int> ans(n, 0);

        dfs2(0, newAdj, ans);

        return ans;
    }
};