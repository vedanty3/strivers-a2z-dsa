class Solution {
	public:
		vector<int> bfsOfGraph(int V, vector<int> adj[]) {
			vector<int>ans;
			vector<bool>vis(V, false);

			queue<int>q;
			q.push(0);
			vis[0] = 1;

			while(!q.empty()) {
				int node = q.front();
				q.pop();
				ans.push_back(node);

				for(auto adj_node : adj[node]) {
					if(!vis[adj_node]) {
						vis[adj_node] = 1;
						q.push(adj_node);
					}
				}
			}


			return ans;
		}
};
