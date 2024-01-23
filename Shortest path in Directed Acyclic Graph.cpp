class Solution {
	public:
		void topo_sort(int src, stack<int>&st, vector<bool>&vis, vector<pair<int, int>>adj[]) {
			vis[src] = true;

			for(auto adj_node : adj[src]) {
				if(!vis[adj_node.first]) {
					topo_sort(adj_node.first, st, vis, adj);
				}
			}

			st.push(src);
		}

		vector<int> shortestPath(int N,int M, vector<vector<int>>& edges) {
			vector<bool>vis(N, false);
			vector<pair<int, int>>adj[N];
			stack<int>st;

			for(int i=0; i<M; ++i) {
				int u = edges[i][0];
				int v = edges[i][1];
				int wt = edges[i][2];
				adj[u].push_back({v, wt});
			}

			for(int i=0; i<N; ++i) {
				if(!vis[i]) {
					topo_sort(i, st, vis, adj);
				}
			}

			vector<int>dist(N, 1e9);
			dist[0] = 0;

			while(!st.empty()) {
				int node = st.top();
				st.pop();

				for(auto adj_node : adj[node]) {
					int v = adj_node.first;
					int wt = adj_node.second;

					if(dist[node] + wt < dist[v]) {
						dist[v] = dist[node] + wt;
					}
				}
			}

			for(int i=0; i<dist.size(); ++i) {
				if(dist[i]==1e9) {
					dist[i] = -1;
				}
			}

			return dist;
		}
};

