class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        if(root==nullptr) {
            return {};
        }
        
        queue<TreeNode*>q;
        q.push(root);
        vector<vector<int>>ans;
        
        while(!q.empty()) {
            int size = q.size();
            vector<int>level;
            for(int i=0; i<size; ++i) {
                TreeNode* node = q.front();
                q.pop();
                if(node->left!=nullptr) {
                    q.push(node->left);
                }
                if(node->right) {
                    q.push(node->right);
                }
                level.push_back(node->val);
            } 
            ans.push_back(level);
        }
        
        return ans;
    }
};
