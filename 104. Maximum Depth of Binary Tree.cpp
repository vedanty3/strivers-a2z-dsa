class Solution {
public:
    int solve(TreeNode* root) {
        if(root==nullptr) {
            return 0;
        }
        return 1 + max(solve(root->left), solve(root->right));
    }

    int maxDepth(TreeNode* root) {
        int ans = solve(root);
        return ans;
    }
};
