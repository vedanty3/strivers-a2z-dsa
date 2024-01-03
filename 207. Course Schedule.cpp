// Cycle Detection: Directed Graph(DFS)

class Solution {
	public:
		bool detectCycleDFS(int src, vector<bool>&vis, vector<bool>&path_vis, vector<int>adj[]) {
			vis[src] = path_vis[src] = true;

			for(auto node : adj[src]) {
				if(!vis[node]) {
					if(detectCycleDFS(node, vis, path_vis, adj)) {
						return true;
					}
				} else if(vis[node] and path_vis[node]) {
					return true;
				}
			}

			path_vis[src] = false;
			return false;
		}

		bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
			vector<int>adj[numCourses];
			vector<bool>vis(numCourses, false), path_vis(numCourses, false);

			for(int i=0; i<prerequisites.size(); ++i) {
				adj[prerequisites[i][1]].push_back(prerequisites[i][0]);
			}

			for(int i=0; i<numCourses; ++i) {
				if(!vis[i]) {
					if(detectCycleDFS(i, vis, path_vis, adj)) {
						return false;
					}
				}
			}

			return true;
		}
};

// Cycle Detection: Directed Graph(Topological Sort - Kahn's Algorithm)

class Solution {
	public:
		bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
			vector<bool> vis(numCourses, false);
			vector<int> adj[numCourses];

			for (int i = 0; i < prerequisites.size(); ++i) {
				adj[prerequisites[i][1]].push_back(prerequisites[i][0]);
			}

			vector<int> indegree(numCourses, 0);
			queue<int> q;
			int topo_sort_size = 0;

			for (int i = 0; i < numCourses; ++i) {
				for (auto node : adj[i]) {
					indegree[node]++;
				}
			}

			for (int i = 0; i < indegree.size(); ++i) {
				if (indegree[i] == 0) {
					q.push(i);
				}
			}

			while (!q.empty()) {
				int node = q.front();
				q.pop();
				++topo_sort_size;

				for (auto adj_node : adj[node]) {
					indegree[adj_node]--;
					if (indegree[adj_node] == 0) {
						q.push(adj_node);
					}
				}
			}

			return !(topo_sort_size!=numCourses);
		}
};


