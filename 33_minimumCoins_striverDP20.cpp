// recusrion approach works for 7/11 cases
typedef long long ll;
ll code(vector<int>ar, int x, int n, int ind,  vector<vector<ll>>&dp) {
	if (x == 0)return 0;
	if (ind == n)return INT_MAX;
	// if (dp[ind + 1][x] != -1)return dp[ind + 1][x];
	int pick = INT_MAX, notpick = INT_MAX;
	if (ar[ind] <= x) {
		pick = code(ar, x - ar[ind], n, ind, dp);
		if (pick != INT_MAX)pick += 1;
	}
	notpick = code(ar, x, n, ind + 1, dp);
	return  min(pick, notpick);
}
#include <bits/stdc++.h>
int minimumElements(vector<int> &ar, int x) {
	int n = ar.size();
	vector<vector<ll>>dp(n + 1, vector<ll>(x + 1, -1));
	sort(ar.begin(), ar.end(), greater<int>());
	int ans = code(ar, x, n, 0, dp);
	if (ans == INT_MAX)return -1;
	else return ans;
}
/* recursion + memorization : doing descending order  might not give the correct
answer always*/

typedef long long ll;
ll code(vector<int>ar, int x, int n, int ind,  vector<vector<ll>>&dp) {
	if (x == 0)return 0;
	if (ind == n)return INT_MAX;
	if (dp[ind + 1][x] != -1)return dp[ind + 1][x];
	int pick = INT_MAX, notpick = INT_MAX;
	if (ar[ind] <= x) {
		pick = code(ar, x - ar[ind], n, ind, dp);
		if (pick != INT_MAX)pick += 1;
	}
	notpick = code(ar, x, n, ind + 1, dp);
	return dp[ind + 1][x] = min(pick, notpick);
}
#include <bits/stdc++.h>
int minimumElements(vector<int> &ar, int x) {
	int n = ar.size();
	vector<vector<ll>>dp(n + 1, vector<ll>(x + 1, -1));
	sort(ar.begin(), ar.end(), greater<int>());
	int ans = code(ar, x, n, 0, dp);
	if (ans == INT_MAX)return -1;
	else return ans;
}
/*bottom up soln*/
