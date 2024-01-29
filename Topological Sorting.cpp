// DFS
#include<bits/stdc++.h>

void dfs(int src, stack<int>&st, vector<bool>&vis, vector<int>adj[]) {
	vis[src] = true;

	for(auto node : adj[src]) {
		if(!vis[node]) {
			dfs(node, st, vis, adj);
		}
	}

	st.push(src);
}

vector<int> topologicalSort(vector<vector<int>> &graph, int edges, int nodes) {
	vector<bool>vis(nodes, false);
	vector<int>ans;
	vector<int>adj[nodes];
	stack<int>st;

	for(int i=0; i<edges; ++i) {
		adj[graph[i][0]].push_back(graph[i][1]);
	}

	for(int i=0; i<nodes; ++i) {
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

// BFS
#include<bits/stdc++.h>

vector<int> topologicalSort(vector<vector<int>> &graph, int edges, int nodes) {
	vector<int>adj[nodes];
	vector<int>indegrees(nodes, 0);
	vector<int>ans;
	queue<int>q;

	for(int i=0; i<edges; ++i) {
		adj[graph[i][0]].push_back(graph[i][1]);
	}

	for(int i=0; i<nodes; ++i) {
		for(auto it : adj[i]) {
			indegrees[it]++;
		}
	}

	for(int i=0; i<indegrees.size(); ++i) {
		if(indegrees[i]==0) {
			q.push(i);
		}
	}

	while(!q.empty()) {
		int node = q.front();
		q.pop();

		ans.push_back(node);

		for(auto adj_node : adj[node]) {
			--indegrees[adj_node];
			if(indegrees[adj_node]==0) {
				q.push(adj_node);
			}
		}
	}

	return ans;
}


