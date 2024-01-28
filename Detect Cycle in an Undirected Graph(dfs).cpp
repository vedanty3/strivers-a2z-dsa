class Graph {
	private:
		bool dfs(int src, int parent, vector<bool>&vis, vector<int>adj[]) {
			vis[src] = true;

			for(auto adj_node : adj[src]) {
				if(!vis[adj_node]) {
					if(dfs(adj_node, src, vis, adj)) {
						return true;
					}
				} else if(adj_node!=parent) {
					return true;
				}
			}
			return false;
		}

	public:
		bool detectCycle(int V, vector<int> adj[]) {
			vector<bool>vis(V, false);

			for(int i=0; i<V; ++i) {
				if(!vis[i]) {
					if(dfs(i, -1, vis, adj)) {
						return true;
					}
				}
			}

			return false;
		}
};
