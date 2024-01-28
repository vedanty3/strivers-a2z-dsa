class Graph {
	private:
		bool bfs(int src, vector<bool>&vis, vector<int>adj[]) {
			queue<pair<int, int>>q;
			q.push({src, -1});
			vis[src] = true;

			while(!q.empty()) {
				int node = q.front().first;
				int parent = q.front().second;
				q.pop();

				for(auto adj_node : adj[node]) {
					if(!vis[adj_node]) {
						vis[adj_node] = true;
						q.push({adj_node, node});
					} else if(adj_node!=parent) {
						return true;
					}
				}
			}

			return false;
		}

	public:
		bool detectCycle(int V, vector<int> adj[]) {
			vector<bool>vis(V, false);

			for(int i=0; i<V; ++i) {
				if(!vis[i]) {
					if(bfs(i, vis, adj)) {
						return true;
					}
				}
			}

			return false;
		}
};
