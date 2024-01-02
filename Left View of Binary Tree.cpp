// Approach 1

vector<int> leftView(Node *root) {
    if(!root) {
        return {};
    }
    queue<Node*>q;
    vector<int>ans;
    q.push(root);
    
    while(!q.empty()) {
        int size = q.size();
        vector<int>level;
        for(int i=0; i<size; ++i) {
            Node* node = q.front();
            q.pop();
            
            if(node->left) {
                q.push(node->left);
            }
            if(node->right) {
                q.push(node->right);
            }
            level.push_back(node->data);
        }
        ans.push_back(level[0]);
    }
    
    return ans;
}

// Approach 2

void solve(int level, Node*root, vector<int>&ans) {
    if(!root) {
        return;
    }
    if(level==ans.size()) {
        ans.push_back(root->data);
    }
    solve(level+1, root->left, ans);
    solve(level+1, root->right, ans);
}

vector<int> leftView(Node *root) {
    vector<int>ans;
    solve(0, root, ans);
    return ans;
}

