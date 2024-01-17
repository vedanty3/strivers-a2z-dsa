class Solution {
	public:
		vector<int> bfsOfGraph(int V, vector<int> adj[]) {
			vector<bool>vis(V, false);
			vector<int>ans;
			vis[0] = true;
			queue<int>q;
			q.push(0);

			while(!q.empty()) {
				int node = q.front();
				q.pop();

				ans.push_back(node);

				for(auto adj_node : adj[node]) {
					if(!vis[adj_node]) {
						vis[adj_node] = true;
						q.push(adj_node);
					}
				}
			}

			return ans;
		}
};
