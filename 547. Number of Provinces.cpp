class Solution {
	public:
		void dfs(int src, vector<bool>&vis, vector<int>adj[]) {
			vis[src] = true;

			for(auto node : adj[src]) {
				if(!vis[node]) {
					dfs(node, vis, adj);
				}
			}
		}

		int findCircleNum(vector<vector<int>>& isConnected) {
			int n = isConnected.size();
			vector<int>adj[n];

			for(int i=0; i<n; ++i) {
				for(int j=0; j<n; ++j) {
					if(i!=j and isConnected[i][j]==1) {
						adj[i].push_back(j);
						adj[j].push_back(i);
					}
				}
			}

			int provinces = 0;
			vector<bool>vis(n, false);

			for(int i=0; i<n; ++i) {
				if(!vis[i]) {
					++provinces;
					dfs(i, vis, adj);
				}
			}

			return provinces;
		}
};
