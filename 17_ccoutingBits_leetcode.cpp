class Solution {
public:
	vector<int> countBits(int n) {
		vector<int>dp(n + 1);
		dp[0] = 0;
		for (int i = 1; i <= n; i++) {
			if (i & 1)dp[i] = dp[i - 1] + 1;
			else {
				dp[i] = dp[i / 2];
			}
		}       return dp;
	}
};