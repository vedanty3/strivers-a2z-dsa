void dfs(int src, vector<bool>&vis, vector<int>adj[]) {
	vis[src] = true;

	for(auto adj_node : adj[src]) {
		if(!vis[adj_node]) {
			dfs(adj_node, vis, adj);
		}
	}
}

int findNumOfProvinces(vector<vector<int>>& roads, int n) {
	int provinces = 0;
	vector<bool>vis(n, false);
	vector<int>adj[n];

	for(int i=0; i<n; ++i) {
		for(int j=0; j<n; ++j) {
			if(roads[i][j]==1 and i!=j) {
				adj[i].push_back(j);
				adj[j].push_back(i);
			}
		}
	}

	for(int i=0; i<n; ++i) {
		if(!vis[i]) {
			++provinces;
			dfs(i, vis, adj);
		}
	}

	return provinces;
}
