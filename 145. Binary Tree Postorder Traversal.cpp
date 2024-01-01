// Approach 1

class Solution {
public:
    void solve(vector<int>&ans, TreeNode* root) {
        if(root==nullptr) {
            return;
        }
        
        solve(ans, root->left);
        solve(ans, root->right);
        ans.push_back(root->val);
    }
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int>ans;
        solve(ans, root);
        return ans;
    }
};

// Approach 2

class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        if(root==nullptr) {
            return {};
        }
        
        TreeNode* curr = root;
        vector<int>ans;
        stack<TreeNode*>st1, st2;
        st1.push(curr);
        
        while(!st1.empty()) {
            curr = st1.top();
            st1.pop();
            st2.push(curr);
            if(curr->left!=nullptr) {
                st1.push(curr->left);
            }
            if(curr->right!=nullptr) {
                st1.push(curr->right);
            }
        }
        
        while(!st2.empty()) {
            ans.push_back(st2.top()->val);
            st2.pop();
        }
        
        return ans;
    }
};

// Approach 3

class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        TreeNode* curr = root;
        vector<int>ans;
        stack<TreeNode*>st;
        
        while(curr!=nullptr or !st.empty()) {
            if(curr!=nullptr) {
                st.push(curr);
                curr = curr->left;
            } else {
                TreeNode* temp = st.top()->right;
                if(temp==nullptr) {
                    temp = st.top();
                    st.pop();
                    ans.push_back(temp->val);
                    while(!st.empty() and temp==st.top()->right) {
                        temp = st.top();
                        st.pop();
                        ans.push_back(temp->val);
                    }
                } else {
                    curr = temp;
                }
            }
        }
        
        return ans;
    }
};
