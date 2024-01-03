// DFS

class Solution {
	public:
		void dfs(int src, stack<int>&st, vector<bool>&vis, vector<int>adj[]) {
			vis[src] = true;

			for(auto node : adj[src]) {
				if(!vis[node]) {
					dfs(node, st, vis, adj);
				}
			}

			st.push(src);
		}
		vector<int> topoSort(int V, vector<int> adj[]) {
			stack<int>st;
			vector<int>ans;
			vector<bool>vis(V, false);

			for(int i=0; i<V; ++i) {
				if(!vis[i]) {
					dfs(i, st, vis, adj);
				}
			}

			while(!st.empty()) {
				ans.push_back(st.top());
				st.pop();
			}

			return ans;
		}
};

// BFS

class Solution {
	public:
		vector<int> topoSort(int V, vector<int> adj[]) {
			vector<int>ans;
			vector<int>indegree(V, 0);
			queue<int>q;

			for(int i=0; i<V; ++i) {
				for(auto node : adj[i]) {
					indegree[node]++;
				}
			}

			for(int i=0; i<indegree.size(); ++i) {
				if(indegree[i]==0) {
					q.push(i);
				}
			}

			while(!q.empty()) {
				int node = q.front();
				ans.push_back(node);
				q.pop();

				for(auto adj_node : adj[node]) {
					indegree[adj_node]--;
					if(indegree[adj_node]==0) {
						q.push(adj_node);
					}
				}
			}

			return ans;
		}
};
