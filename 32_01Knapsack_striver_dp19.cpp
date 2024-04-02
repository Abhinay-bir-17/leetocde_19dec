/* recusrion : works for 1/3 test cases. here i just go thru all subsets nd pick the value
of subset with highest value of its weights*/
#include <bits/stdc++.h>
void code(vector<int>w, vector<int>v, int n, int mw, int &ans, int ind, int aux_sum) {
	if (ind == n) {
		if (ans < aux_sum)ans = aux_sum; return;
	}
	// if (mw <= 0)return;
	if (w[ind] <= mw)code(w, v, n, mw - w[ind], ans, ind + 1, aux_sum + v[ind]); // inc the el
	code(w, v, n, mw, ans, ind + 1, aux_sum);
}
int knapsack(vector<int> w, vector<int> v, int n, int mw) {
	// Write your code here abhinay
	int ans = INT_MIN;
	code(w, v, n, mw, ans, 0, 0);
	return ans;
}

// rec + memorization: works
int code(vector<int>w, vector<int>v, int n, int mw, vector<vector<int>>&dp, int ind) {
	if (ind == n)return 0;
	if (mw <= 0)return 0;
	if (dp[ind + 1][mw] != -1)return dp[ind + 1][mw];

	int pick = 0, notpick = 0;
	if (w[ind] <= mw) pick = v[ind] + code(w, v, n, mw - w[ind], dp, ind + 1);
	notpick = code(w, v, n, mw, dp, ind + 1);
	dp[ind + 1][mw] = max(pick , notpick) ;
	return dp[ind + 1][mw];
}
int knapsack(vector<int> w, vector<int> v, int n, int mw) {
	// Write your code here abhinay
	vector<vector<int>>dp(n + 1, vector(mw + 1, -1));
	return code(w, v, n, mw, dp, 0);
}
// bottom up soln:
int knapsack(vector<int> w, vector<int> v, int n, int mw) {
	// Write your code here abhinay
	vector<vector<int>>dp(n + 1, vector<int>(mw + 1, 0));
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= mw; j++) {
			if (j < w[i - 1])dp[i][j] = dp[i - 1][j];
			else {
				dp[i][j] = max(dp[i - 1][j], v[i - 1] + dp[i - 1][j - w[i - 1]]);
			}
		}
	} return dp[n][mw];
}