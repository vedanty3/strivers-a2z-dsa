// BFS

class Solution {
	public:
		bool bfs(int src, vector<int>&color, vector<int>adj[]) {
			color[src] = 0;
			queue<int>q;
			q.push(src);

			while(!q.empty()) {
				int node = q.front();
				q.pop();

				for(auto adj_node : adj[node]) {
					if(color[adj_node]==-1) {
						color[adj_node] = !color[node];
						q.push(adj_node);
					} else if(color[adj_node]==color[node]) {
						return false;
					}
				}
			}

			return true;
		}

		bool isBipartite(vector<vector<int>>& graph) {
			int n = graph.size();
			vector<int>adj[n];
			vector<int>color(n+1, -1);

			for(int i=0; i<n; ++i) {
				for(int j=0; j<graph[i].size(); ++j) {
					adj[i].push_back(graph[i][j]);
				}
			}

			for(int i=0; i<n; ++i) {
				if(color[i]==-1 and !bfs(i, color, adj)) {
					return false;
				}
			}

			return true;
		}
};

// DFS

class Solution {
	public:
		bool dfs(int src, int col, vector<int>& color, vector<int> adj[]) {
			color[src] = col;

			for (auto adj_node : adj[src]) {
				if (color[adj_node] == -1) {
					if(!dfs(adj_node, !col, color, adj)) {
						return false;
					}
				} else if (color[adj_node] == color[src]) {
					return false;
				}
			}

			return true;
		}

		bool isBipartite(vector<vector<int>>& graph) {
			int n = graph.size();
			vector<int> adj[n];
			vector<int> color(n + 1, -1);

			for (int i = 0; i < n; ++i) {
				for (int j = 0; j < graph[i].size(); ++j) {
					adj[i].push_back(graph[i][j]);
				}
			}

			for (int i = 0; i < n; ++i) {
				if (color[i] == -1 and !dfs(i, 0, color, adj)) {
					return false;
				}
			}

			return true;
		}
};
