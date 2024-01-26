void swapNumber(int &a, int &b) {
	a = a^b;
	b = b^a;
	a = a^b;
}
