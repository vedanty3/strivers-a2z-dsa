class Solution {
	public:
		void solve(TreeNode* root, string s, vector<string>&ans) {
			if(!root) {
				return;
			}

			if(!root->left and !root->right) {
				s += to_string(root->val);
				ans.push_back(s);
				return;
			}

			if(root->left) {
				solve(root->left, s + to_string(root->val) + "->", ans);
			}
			if(root->right) {
				solve(root->right, s + to_string(root->val) + "->", ans);
			}
		}

		vector<string> binaryTreePaths(TreeNode* root) {
			string s;
			vector<string>ans;
			solve(root, s, ans);
			return ans;
		}
};
