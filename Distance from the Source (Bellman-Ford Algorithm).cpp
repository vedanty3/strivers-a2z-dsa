class Solution {
	public:
		vector<int> bellman_ford(int V, vector<vector<int>>& edges, int S) {
			vector<int>dist(V, 1e8);
			dist[S] = 0;

			for(int i=0; i<V-1; ++i) {
				for(auto node : edges) {
					int u = node[0];
					int v = node[1];
					int wt = node[2];
					if(dist[u]!=1e8 and wt + dist[u] < dist[v]) {
						dist[v] = wt + dist[u];
					}
				}
			}

			for(auto node : edges) {
				int u = node[0];
				int v = node[1];
				int wt = node[2];
				if(dist[u]!=1e8 and wt + dist[u] < dist[v]) {
					return {-1};
				}
			}

			return dist;
		}
};
