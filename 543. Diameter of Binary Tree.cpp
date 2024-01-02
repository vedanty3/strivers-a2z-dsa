class Solution {
public:
    int solve(TreeNode* root, int&ans) {
        if(!root) {
            return 0;
        }

        int lh = solve(root->left, ans);
        int rh = solve(root->right, ans);

        ans = max(ans, lh+rh);

        return 1 + max(lh, rh);
    }
    int diameterOfBinaryTree(TreeNode* root) {
        int ans = 0;
        solve(root, ans);
        return ans;
    }
};
