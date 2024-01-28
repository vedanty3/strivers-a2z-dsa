int findXORInRange(int n) {
	if(n%4==0) {
		return n;
	} else if(n%4==1) {
		return 1;
	} else if(n%4==2) {
		return n+1;
	} else {
		return 0;
	}
}

int findXOR(int L, int R) {
	return findXORInRange(L-1) ^ findXORInRange(R);
}
