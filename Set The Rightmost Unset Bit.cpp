int setBits(int N) {
	int first_unset = 0;
	int b = N;
	int fl = 0;

	while(b) {
		if(!(b&1)) {
			fl = 1;
			break;
		}
		b>>=1;
		++first_unset;
	}

	if(!fl) {
		--first_unset;
	}

	N = N | (1<<first_unset);
	return N;
}
