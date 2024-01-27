class Solution {
	public:
		bool isPalindrome(int x) {
			string x_reverse = to_string(x);
			reverse(x_reverse.begin(), x_reverse.end());
			return to_string(x)==x_reverse;
		}
};
