#include<bits/stdc++.h>

int getPrecedence(char ch) {
	if(ch=='^') {
		return 3;
	} else if(ch=='*' or ch=='/') {
		return 2;
	} else if(ch=='-' or ch=='+') {
		return 1;
	}

	return -1;
}

string infixToPostfix(string s) {
	int n = s.size();
	string ans;
	stack<char>st;

	for(int i=0; i<n; ++i) {
		if(s[i]=='(') {
			st.push(s[i]);
		} else if((s[i]>='0' and s[i]<='9') or (s[i]<='z' and s[i]>='a')) {
			ans.push_back(s[i]);
		} else if(s[i]==')') {
			while(st.top()!='(') {
				ans.push_back(st.top());
				st.pop();
			}
			st.pop();
		} else {
			while(!st.empty() and getPrecedence(s[i])<=getPrecedence(st.top())) {
				ans.push_back(st.top());
				st.pop();
			}
			st.push(s[i]);
		}
	}

	while(!st.empty()) {
		ans.push_back(st.top());
		st.pop();
	}

	return ans;
}
