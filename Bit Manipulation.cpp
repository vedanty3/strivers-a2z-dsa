vector<int> bitManipulation(int num, int i) {
	vector<int>ans;
	int bit_value = (num & (1<<i-1)) ? 1 : 0;
	int set_bit = (1<<i-1)|num;
	int clear_bit = 1<<(i-1);
	clear_bit = ~clear_bit;
	clear_bit = clear_bit&num;
	ans.push_back(bit_value);
	ans.push_back(set_bit);
	ans.push_back(clear_bit);
	return ans;
}
