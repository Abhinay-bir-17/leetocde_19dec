#include<bits/stdc++.h>
string findLCS(int n, int m, string &ar, string &br) {
	// Write your code here.
	vector<vector<int>>dp(n + 1, vector<int>(m + 1, 0));
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (ar[i - 1] == br[j - 1])dp[i][j] = 1 + dp[i - 1][j - 1];
			else dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
		}
	}
	// focus here abhinay bir
	string ans = "";
	while (m > 0 && n > 0) {
		if (ar[n - 1] == br[m - 1]) {
			ans += ar[n - 1];
			m = m - 1; n = n - 1;
		} else {
			if (dp[n - 1][m] == dp[n][m]) {
				n -= 1;
			} else m -= 1;
		}
	} //cout<<"ans :"<<ans<<endl;
	for (int i = 0, j = ans.length() - 1; i < j;) {
		swap(ans[i], ans[j]);
		i += 1; j -= 1;
	} return ans;
}