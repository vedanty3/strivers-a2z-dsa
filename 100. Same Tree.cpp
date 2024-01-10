class Solution {
	public:
		bool solve(TreeNode* p, TreeNode* q) {
			if (!p and !q) {
				return true;
			}
			if (!p) {
				return false;
			}
			if (!q) {
				return false;
			}
			if (p->val != q->val) {
				cout << p->val << " " << q->val << endl;
				return false;
			}

			bool left_ans = solve(p->left, q->left);
			bool right_ans = solve(p->right, q->right);

			return left_ans and right_ans;
		}
		bool isSameTree(TreeNode* p, TreeNode* q) {
			return solve(p, q);
		}
};
