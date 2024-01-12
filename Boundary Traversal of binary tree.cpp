class Solution {
	public:
		bool isLeaf(Node* root) {
			if(!root->left and !root->right) {
				return true;
			}
			return false;
		}

		void addLeft(Node* root, vector<int>&ans) {
			Node* curr = root->left;
			while(curr) {
				if(!isLeaf(curr)) {
					ans.push_back(curr->data);
				}
				if(curr->left) {
					curr = curr->left;
				} else {
					curr = curr->right;
				}
			}
		}

		void addLeaves(Node* root, vector<int>&ans) {
			if(isLeaf(root)) {
				ans.push_back(root->data);
				return;
			}
			if(root->left) {
				addLeaves(root->left, ans);
			}
			if(root->right) {
				addLeaves(root->right, ans);
			}
		}

		void addRight(Node* root, vector<int>&ans) {
			vector<int>temp;
			Node* curr = root->right;

			while(curr) {
				if(!isLeaf(curr)) {
					temp.push_back(curr->data);
				}
				if(curr->right) {
					curr = curr->right;
				} else {
					curr = curr->left;
				}
			}

			for(int i=temp.size()-1; i>=0; --i) {
				ans.push_back(temp[i]);
			}
		}

		vector <int> boundary(Node *root) {
			vector<int>ans;
			if(!root) {
				return ans;
			}
			if(!isLeaf(root)) {
				ans.push_back(root->data);
			}
			addLeft(root, ans);
			addLeaves(root, ans);
			addRight(root, ans);
			return ans;
		}
};

