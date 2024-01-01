int pivotIndex(vector<int>& ar) {
	int n = ar.size();
	if (n == 1)return 0;

	int dp[n]; dp[0] = ar[0];
	for (int i = 1; i < n; i++)dp[i] = dp[i - 1] + ar[i];

	// if (dp[n - 1] & 1)return -1;

	// check if 1st index is pivot index
	if (dp[0] == dp[n - 1])return 0;

	for (int i = 1; i < n - 1; i++) {
		if ((dp[i] - ar[i]) == (dp[n - 1] - dp[i]))return i;
	}
	// if last index is pivot index
	if (dp[n - 2] == 0)return n - 1;
	return -1; 7
}