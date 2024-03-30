// recursive soln: 25/50 test cases
int code(vector<int>ar, int n, int k, int ind, int curSum) {
	if (ind == n) {
		if (k == curSum)return 1;
		else return 0;
	}
	return ( code(ar, n, k, ind + 1, curSum + ar[ind]) +
	         code(ar, n, k, ind + 1, curSum));
}
int findWays(vector<int>& ar, int k) {
	// Write your code here.
	int n = ar.size();
	return code(ar, n, k, 0, 0);
}
// rec + memo: working for 48/50 test cases. after commenting the 24th line 50/50
const int M = 1e9 + 7;
typedef long long ll;
int code(vector<int>ar, int n, int k, int ind, int curSum, vector<vector<int>>&dp) {
	if (ind == n) {
		if (k == curSum)return 1;
		else return 0;
	}
	if (curSum > k)return 0;
	// if (curSum == k)return 1;
	if (dp[ind + 1][k - curSum] != -1)return dp[ind + 1][k - curSum];
	ll pick = (code(ar, n, k, ind + 1, curSum + ar[ind], dp)) % M;
	ll not_pick = (code(ar, n, k, ind + 1, curSum, dp)) % M;

	return dp[ind + 1][k - curSum] = (pick + not_pick) % M;
}
int findWays(vector<int>& ar, int k) {
	// Write your code here.
	int n = ar.size(); vector<vector<int>>dp(n + 1, vector<int>(k + 1, -1));
	return code(ar, n, k, 0, 0, dp) % M;
}

// bottom up approach:
int findWays(vector<int>& ar, int k) {
	// Write your code here
	int  n = ar.size();
	vector<vector<int>>dp(n + 1, vector<int>(k + 1, 0));
	for (int i = 0; i <= n; i++)dp[i][0] = 1;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= k; j++) {
			dp[i][j] = dp[i - 1][j];
			if ((j - ar[i - 1]) >= 0)dp[i][j] += dp[i - 1][j - ar[i - 1]];
		}
	} return dp[n][k];
}
