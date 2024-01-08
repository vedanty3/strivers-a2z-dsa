class Solution {
	public:
		vector<vector<int>> verticalTraversal(TreeNode* root) {
			vector<vector<int>>ans;
			queue<pair<TreeNode*, pair<int, int>>>q;
			map<int, map<int, multiset<int>>>mpp;

			q.push({root, {0, 0}});

			while(!q.empty()) {
				TreeNode* node = q.front().first;
				int vertical_line = q.front().second.second;
				int level = q.front().second.first;
				q.pop();

				mpp[vertical_line][level].insert(node->val);

				if(node->left) {
					q.push({node->left, {level+1, vertical_line-1}});
				}

				if(node->right) {
					q.push({node->right, {level+1, vertical_line+1}});
				}
			}

			for(auto it : mpp) {
				vector<int>temp;
				for(auto i : it.second) {
					for(auto s : i.second) {
						temp.push_back(s);
					}
				}
				ans.push_back(temp);
			}

			return ans;
		}
};
