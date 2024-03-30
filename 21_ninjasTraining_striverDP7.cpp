// recursion approach 14th march 2024, done on
#include<bits/stdc++.h>
int solve(int r, int c, int n, vector<vector<int>>&ar) {
	if (r == n)return 0;
	int ans = INT_MIN;
	for (int i = 0; i < 3; i++) {
		if (i != c) {
			ans = max(ans, ar[r][i] + solve(r + 1, i, n, ar));
		}
	} return ans;

}
int ninjaTraining(int n, vector<vector<int>> &ar) {
	// Write your code here wtf
	int ans = INT_MIN;
	for (int i = 0; i < 3; i++) {
		ans = max (ans, ar[0][i] + solve(1, i, n, ar));
	} return ans;

}

// below is the rec+memorization
#include<bits/stdc++.h>
int solve(int r, int c, int n, vector<vector<int>>&ar, vector<vector<int>>&dp) {
	if (r == n)return 0;
	int ans = INT_MIN;
	for (int i = 0; i < 3; i++) {
		if (i != c) {
			if (dp[r][i] == -1)dp[r][i] = ar[r][i] + solve(r + 1, i, n, ar, dp);
			ans = max(ans, dp[r][i]);
		}
	}   return ans;
}

int ninjaTraining(int n, vector<vector<int>> &ar) {
	// Write your code here wtf
	int ans = INT_MIN;
	vector<vector<int>>dp(n, vector<int>(3, -1));
	for (int i = 0; i < 3; i++) {
		dp[0][i] =  ar[0][i] + solve(1, i, n, ar, dp);
		ans = max(ans, dp[0][i]);
	}
	for (int i = 0; i < dp.size(); i++) {
		for (int j = 0; j < dp[i].size(); j++)cout << dp[i][j] << " ";
		cout << endl;
	}
	return ans;
}
// bottom up soln : works
int ninjaTraining(int n, vector<vector<int>> &ar) {
	// Write your code here.
	for (int i = 1; i < n; i++) {
		for (int j = 0; j < 3; j++) {
			if (j == 0)ar[i][j] += max(ar[i - 1][1], ar[i - 1][2]);
			else if (j == 1)ar[i][j] += max(ar[i - 1][0], ar[i - 1][2]);
			else ar[i][j] += max(ar[i - 1][0], ar[i - 1][1]);
		}
	} int ans = INT_MIN;
	for (int i = 0; i < 3; i++)ans = max(ans, ar[n - 1][i]); return ans;
}