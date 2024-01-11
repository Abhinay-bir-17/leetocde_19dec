int minimizeSet(int d1, int d2, int cnt1, int cnt2) {
	int sd, bd ;
	int sdc, bdc;
	if (d1 > d2) { sd = d2; bd = d1; sdc = cnt2; bdc = cnt1; }
	else {
		sd = d1; bd = d2;
		sdc = cnt1; bdc = cnt2;
	}
	int temp1 = 0;
	for (int i = 1;; i++) {
		if (sdc != 0) {
			if (i % sd) {
				sdc -= 1;
				if (i % bd)temp1 += 1;// divides sd but not bd
			} else {
				if ( bdc != 0 && (i % bd))bdc -= 1;
			}
		} else {
			if (bdc != 0 && (i % bd))bdc -= 1;
			else if (bdc != 0 && (i % bd == 0) && temp1 != 0 && (i % sd)) {bdc -= 1; temp1 -= 1;}
		}
		if (sdc == 0 && bdc == 0)return i;
	}
}
