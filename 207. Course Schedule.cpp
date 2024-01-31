class Solution {
	public:
		bool canFinish(int V, vector<vector<int>>& edges) {
			int n = edges.size();
			vector<int>adj[V];

			for(int i=0; i<n; ++i) {
				adj[edges[i][1]].push_back(edges[i][0]);
			}

			int taken_courses = 0;
			vector<int>indegrees(V, 0);
			queue<int>q;

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
				++taken_courses;

				for(auto adj_node : adj[node]) {
					indegrees[adj_node]--;
					if(indegrees[adj_node]==0) {
						q.push(adj_node);
					}
				}
			}

			return taken_courses==V;
		}
};
