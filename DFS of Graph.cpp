class Solution {
	public:
		void dfs(int src, vector<bool>&vis, vector<int>&ans, vector<int>adj[]) {
			ans.push_back(src);
			vis[src] = true;

			for(auto adjNode : adj[src]) {
				if(!vis[adjNode]) {
					dfs(adjNode, vis, ans, adj);
				}
			}
		}
		vector<int> dfsOfGraph(int V, vector<int> adj[]) {
			vector<bool>vis(V, false);
			vector<int>ans;

			dfs(0, vis, ans, adj);

			return ans;
		}
};

