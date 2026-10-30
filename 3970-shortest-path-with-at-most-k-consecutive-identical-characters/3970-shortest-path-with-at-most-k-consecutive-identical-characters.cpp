class Solution {
public:
    int shortestPath(int n, vector<vector<int>>& edges, string labels, int k) {

        vector<vector<pair<int, int>>> adj(n);

        for (auto it : edges) {
            int u = it[0];
            int v = it[1];
            int wt = it[2];

            adj[u].push_back({v, wt});
        }

        vector<vector<int>> dist(n, vector<int>(k + 1, INT_MAX));

        // {distance, node, consecutive count}
        priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>,
                       greater<tuple<int, int, int>>>
            pq;

        dist[0][1] = 0;
        pq.push({0, 0, 1});

        while (!pq.empty()) {

            auto [d, node, cnt] = pq.top();
            pq.pop();

            if (d > dist[node][cnt])
                continue;

            if (node == n - 1)
                return d;

            for (auto [nbh, wt] : adj[node]) {

                int newCnt;

                if (labels[nbh] == labels[node])
                    newCnt = cnt + 1;
                else
                    newCnt = 1;

                if (newCnt > k)
                    continue;

                if (d + wt < dist[nbh][newCnt]) {

                    dist[nbh][newCnt] = d + wt;

                    pq.push({d + wt, nbh, newCnt});
                }
            }
        }

        return -1;
    }
};