/* so we have to find longest consecutive subarray
with atmost 3 0's */
int code(vector<int>&ar, int n) {
	int l = 0, r = 0;
	int ans = 0;
	while (r < n) {
		if (ar[r] == 1) {
			ans = max(ans, r - l + 1);
			r += 1;
		} else {
			ans = max(ans, r - l);
			l = r + 1;
			r += 1;
		}
	}
	return ans;
}
int longestOnes(vector<int>&ar, int k) {
	// focus here abhinay bir you can do it
	int n = ar.size();

	if (k == 0) {
		// find longest subarray of 1s
		int ans = code(ar, n); cout << "ans is:" << ans << endl; return ans;
	}
	if (n == 1) {return 1;}
	int l = 0, r = 1; int cnt = 0;
	if (ar[l] == 0)cnt += 1;

	int ans = 0;
	while (r < n) {
		if (ar[r] == 0)cnt += 1;
		if (cnt > k) {
			ans = max(ans, r  - l);
			if (ar[l] == 0) {cnt -= 1; r += 1;}
			else { r += 1;}

			l += 1;
		} else {
			ans = max(ans, r - l + 1);
			r += 1;
		}
	} return ans;
}