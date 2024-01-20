class Solution {
	public:
		bool lemonadeChange(vector<int>& bills) {
			int fives = 0;
			int tens = 0;
			int twentys = 0;
			int n = bills.size();

			for(int i=0; i<n; ++i) {
				if(bills[i]==5) {
					++fives;
				} else if(bills[i]==10 and fives) {
					--fives;
					++tens;
				} else if(bills[i]==20 and tens and fives) {
					--tens;
					--fives;
					++twentys;
				} else if(bills[i]==20 and fives>=3) {
					fives -= 3;
					++twentys;
				} else {
					return false;
				}
			}

			return true;
		}
};
