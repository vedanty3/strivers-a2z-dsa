class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        int m = flights.size();
        vector<pair<int, int>>adj[n];

        for (int i = 0; i < m; ++i) {
            int fromi = flights[i][0];
            int toi = flights[i][1];
            int pricei = flights[i][2];
            adj[fromi].push_back({toi, pricei});
        }

        vector<int>dist(n, 1e9);
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>>pq;
        pq.push({0, {src, 0}});

        while (!pq.empty()) {
            int stops = pq.top().first;
            int node = pq.top().second.first;
            int dis = pq.top().second.second;
            pq.pop();

            if (stops > k) {
                continue;
            }

            for (auto &p : adj[node]) {
                int edge_wt = p.second;
                int v = p.first;
                if (dist[v] > edge_wt + dis and stops <= k) {
                    dist[v] = edge_wt + dis;
                    pq.push({stops + 1, {v, dist[v]}});
                }
            }
        }

        if (dist[dst] == 1e9) {
            return -1;
        }

        return dist[dst];
    }
};