class Solution {
	public:
		vector <int> dijkstra(int V, vector<vector<int>> adj[], int S) {
			priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>>pq;
			vector<int>dist(V, 1e9);
			dist[S] = 0;
			pq.push({0, S});

			while(!pq.empty()) {
				int wt = pq.top().first;
				int val = pq.top().second;
				pq.pop();

				for(auto adjNode : adj[val]) {
					if(wt + adjNode[1] < dist[adjNode[0]]) {
						dist[adjNode[0]] = wt + adjNode[1];
						pq.push({dist[adjNode[0]], adjNode[0]});
					}
				}
			}

			return dist;

		}
};
