// Approach 1

class Solution {
	public:
		int minAddToMakeValid(string s) {
			int stack = 0;
			int ans = 0;
			int n = s.size();

			for(int i=0; i<n; ++i) {
				if(s[i]=='(') {
					++stack;
				} else {
					if(stack>0) {
						--stack;
					} else {
						++ans;
					}
				}
			}

			return ans + stack;
		}
};

// Approach 2

class Solution {
	public:
		int minAddToMakeValid(string s) {
			int n = s.size();
			int ans = 0;
			stack<char> st;

			for (int i = 0; i < n; ++i) {
				if (s[i] == '(') {
					st.push('(');
				} else {
					if (st.empty()) {
						++ans;
					} else if (st.top() == '(') {
						st.pop();
					}
				}
			}

			return ans + st.size();
		}
};
