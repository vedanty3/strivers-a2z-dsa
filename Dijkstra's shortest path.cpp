vector<int> dijkstra(vector<vector<int>> &edges, int vertices, int M, int source) {
	vector<pair<int, int>>adj[vertices];
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>>pq;
	pq.push({0, source});
	vector<int>dist(vertices, INT_MAX);
	dist[source] = 0;

	for(auto it : edges) {
		adj[it[0]].push_back({it[1], it[2]});
		adj[it[1]].push_back({it[0], it[2]});
	}

	while(!pq.empty()) {
		int wt = pq.top().first;
		int node = pq.top().second;
		pq.pop();

		for(auto it : adj[node]) {
			int v = it.first;
			int new_wt = it.second;
			if(dist[v] > dist[node] + new_wt) {
				dist[v] = dist[node] + new_wt;
				pq.push({dist[v], v});
			}
		}
	}

	return dist;
}
