class Solution {
	public:
		// Function to detect cycle in a directed graph.
		bool isCyclic(int V, vector<int> adj[]) {
			vector<int>indegrees(V, 0);
			queue<int>q;
			int topo_sort_len = 0;

			for(int i=0; i<V; ++i) {
				for(auto node : adj[i]) {
					indegrees[node]++;
				}
			}

			for(int i=0; i<V; ++i) {
				if(indegrees[i]==0) {
					q.push(i);
				}
			}

			while(!q.empty()) {
				int node = q.front();
				q.pop();
				++topo_sort_len;

				for(auto adj_node : adj[node]) {
					indegrees[adj_node]--;
					if(indegrees[adj_node]==0) {
						q.push(adj_node);
					}
				}
			}

			return topo_sort_len!=V;


		}
};
