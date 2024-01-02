class Solution {
  public:
    void dfs(int src, vector<int>&vis, vector<int>adj[], vector<int>&ans) {
        vis[src] = 1;
        ans.push_back(src);
        
        for(auto node : adj[src]) {
            if(!vis[node]) {
                dfs(node, vis, adj, ans);
            }
        }
    }
    
    vector<int> dfsOfGraph(int V, vector<int> adj[]) {
        vector<int>vis(V, 0);
        vector<int>ans;
        
        for(int i=0; i<V; ++i) {
            if(!vis[i]) {
                dfs(i, vis, adj, ans);
            }
        }
        
        return ans;
    }
};
