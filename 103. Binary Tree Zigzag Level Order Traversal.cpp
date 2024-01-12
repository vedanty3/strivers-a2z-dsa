class Solution {
	public:
		vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
			if(!root) {
				return {};
			}
			int fl = 0;
			vector<vector<int>> ans;
			queue<TreeNode*> q;
			q.push(root);

			while (!q.empty()) {
				int size = q.size();
				vector<int> ds;
				for (int i = 0; i < size; ++i) {
					TreeNode* node = q.front();
					q.pop();
					if (node->left!=nullptr) {
						q.push(node->left);
					}
					if (node->right!=nullptr) {
						q.push(node->right);
					}
					ds.push_back(node->val);
				}
				fl = !fl;
				if (!fl) {
					reverse(ds.begin(), ds.end());
				}
				ans.push_back(ds);
			}

			return ans;
		}
};
