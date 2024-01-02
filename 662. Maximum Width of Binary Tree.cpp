class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
        if(root==nullptr) {
            return 0;
        }
        
        int ans = 0;
        queue<pair<TreeNode*, int>>q;
        q.push({root, 0});
        
        while(!q.empty()) {
            int size = q.size();
            int min_indx = q.front().second;
            int left_most, right_most;
            
            for(int i=0; i<size; ++i) {
                TreeNode* node = q.front().first;
                long long int curr_indx = q.front().second - min_indx;
                q.pop();
                
                if(i==0) {
                    left_most = curr_indx;
                }
                if(i==size-1) {
                    right_most = curr_indx;
                }
                if(node->left) {
                    q.push({node->left, 2*curr_indx+1});
                }
                if(node->right) {
                    q.push({node->right, 2*curr_indx+2});
                }
            }
            ans = max(ans, right_most - left_most + 1);
        }
        
        return ans;
    }
};
