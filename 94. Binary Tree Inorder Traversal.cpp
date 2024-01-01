// Approach 1

class Solution {
public:
    void solve(vector<int>&ans, TreeNode* root) {
        if(root==nullptr) {
            return;
        }
        
        solve(ans, root->left);
        ans.push_back(root->val);
        solve(ans, root->right);
    }
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int>ans;
        solve(ans, root);
        return ans;
    }
};

// Approach 2

class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        TreeNode* curr = root;
        vector<int>ans;
        stack<TreeNode*>st;
        
        while(1) {
            if(curr) {
                st.push(curr);
                curr = curr->left;
            } else {
                if(st.empty()) {
                    break;
                }
                curr = st.top();
                st.pop();
                ans.push_back(curr->val);
                curr = curr->right;
            }
        }
        
        return ans;
    }
};

// Morris Inorder Traversal

class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int>ans;
        TreeNode* curr = root;
        
        while(curr!=nullptr) {
            if(curr->left!=nullptr) {
                TreeNode* prev = curr->left;
                
                while(prev->right!=nullptr and prev->right!=curr) {
                    prev = prev->right;
                }
                
                if(prev->right==nullptr) {
                    prev->right = curr;
                    curr = curr->left;
                } else {
                    prev->right = nullptr;
                    ans.push_back(curr->val);
                    curr = curr->right;
                }
            } else {
                ans.push_back(curr->val);
                curr = curr->right;
            }
        }
        
        return ans;
    }
};
