// recursion: works for 4/7 cases
int code(string s, string t, int m, int n, int ind1, int ind2) {
	if (ind1 == m || ind2 == n)return 0;
	if (s[ind1] == t[ind2]) {
		return 1 + code(s, t, m, n, ind1 + 1, ind2 + 1);
	}
	else return max( code(s, t, m, n, ind1 + 1, ind2),
		                 code(s, t, m, n, ind1, ind2 + 1));
}
int lcs(string s, string t) {
	//Write your code here abhinay bir okay? lol!!!
	int m = s.length();
	int n = t.length();
	return code(s, t, m, n, 0, 0);
}

// rec + memo
#include <bits/stdc++.h>
int code(string s, string t, int m, int n, int ind1, int ind2, vector<vector<int>>&dp) {
	if (ind1 == m || ind2 == n)return 0;
	if (s[ind1] == t[ind2]) {
		return 1 + code(s, t, m, n, ind1 + 1, ind2 + 1, dp);
	}
	if (dp[ind1 + 1][ind2 + 1] != -1)return dp[ind1 + 1][ind2 + 1];
	else return dp[ind1 + 1][ind2 + 1] = max( code(s, t, m, n, ind1 + 1, ind2, dp),
		                                     code(s, t, m, n, ind1, ind2 + 1, dp));
}
int lcs(string s, string t) {
	//Write your code here abhinay bir okay? lol!!!
	int m = s.length();
	int n = t.length();
	vector<vector<int>>dp(m + 1, vector<int>(n + 1, -1));
	return code(s, t, m, n, 0, 0, dp);
}

// bottom up approach
#include <bits/stdc++.h>
int lcs(string s, string t) {
	//Write your code here abhinay bir okay? lol!!!
	int m = s.length();
	int n = t.length();
	vector<vector<int>>dp(m + 1, vector<int>(n + 1, 0));
	for (int i = 1; i <= m; i++) {
		for (int j = 1; j <= n; j++) {
			if (s[i - 1] == t[j - 1]) {
				dp[i][j] = 1 + dp[i - 1][j - 1];
			} else {
				dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
			}
		}
	} return dp[m][n];
}
