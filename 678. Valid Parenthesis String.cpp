class Solution {
	public:
		bool checkValidString(string s) {
			int open = 0;
			int star = 0;
			int used = 0;

			for(auto ch : s) {
				if(ch=='(') {
					++open;
				} else if(ch=='*') {
					if(open) {
						--open;
						++used;
					} else {
						++star;
					}
				} else {
					if(open) {
						--open;
					} else if(star) {
						--star;
					} else if(used) {
						--used;
						++star;
					} else {
						return false;
					}
				}
			}

			return open==0;
		}
};
