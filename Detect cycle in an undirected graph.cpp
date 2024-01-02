class Solution {
	public:
		bool isCycle(int V, vector<int> adj[]) {
			vector<bool>vis(V, false);

			for(int src=0; src<V; ++src) {
				if(!vis[src]) {
					queue<pair<int, int>>q;
					vis[src] = 1;
					q.push({src, -1});

					while(!q.empty()) {
						int node = q.front().first;
						int parent = q.front().second;
						q.pop();

						for(auto adjNode : adj[node]) {
							if(vis[adjNode] and parent!=adjNode) {
								return true;
							} else if(!vis[adjNode]) {
								vis[adjNode] = 1;
								q.push({adjNode, node});
							}
						}
					}
				}
			}

			return false;
		}
};
