class Solution {
	public:
		int solve(TreeNode* root) {
			if (!root) {
				return 0;
			}

			int lh = solve(root->left);
			if (lh == -1) {
				return -1;
			}
			int rh = solve(root->right);
			if (rh == -1) {
				return -1;
			}
			if (abs(rh - lh) > 1) {
				return -1;
			}

			return 1 + max(lh, rh);
		}

		bool isBalanced(TreeNode* root) {
			return solve(root) != -1;
		}
};
