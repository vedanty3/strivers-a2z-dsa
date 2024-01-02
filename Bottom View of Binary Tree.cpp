class Solution {
  public:
    vector <int> bottomView(Node *root) {
        map<int, int>mpp;
        vector<int>ans;
        queue<pair<Node*, int>>q;
        q.push({root, 0});
        
        while(!q.empty()) {
                Node* node = q.front().first;
                int vertical_line = q.front().second;
                q.pop();
                
                if(node->left) {
                    q.push({node->left, vertical_line-1});
                }
                
                if(node->right) {
                    q.push({node->right, vertical_line+1});
                }
                
                mpp[vertical_line] = node->data;
        }
        
        for(auto p : mpp) {
            ans.push_back(p.second);
        }
        
        return ans;
    }
};
