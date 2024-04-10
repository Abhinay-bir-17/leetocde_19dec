// recursion works
int code(vector<int>ar, vector<int>cost, int n,  int ind, int aux_sum) {
	if (n == 0)return aux_sum;
	if (ind == n) {
		return aux_sum;
	}
	int pick = INT_MIN, notpick = INT_MIN;
	if (ar[ind] <= n) {
		pick = code(ar, cost, n - ar[ind], ind, aux_sum + cost[ind]);
	}
	else return aux_sum;

	notpick = code(ar, cost, n, ind + 1, aux_sum);
	return max(pick, notpick);
}
int cutRod(vector<int> &cost, int n) {
	// Write your code here.
	vector<int>ar;
	for (int i = 1; i <= n; i++)ar.push_back(i);
	return code(ar, cost, n, 0, 0);
}
// rec + memo
int code(vector<int>ar, vector<int>cost, int n,  int ind, vector<vector<int>>&dp) {
	if (n == 0)return 0;
	if (ind == n) {
		return 0;
	}
	if (dp[ind + 1][n] != -1)return dp[ind + 1][n];
	int pick = INT_MIN, notpick = INT_MIN;
	if (ar[ind] <= n) {
		pick = cost[ind] + code(ar, cost, n - ar[ind], ind, dp);
	}
	else return 0;

	notpick = code(ar, cost, n, ind + 1, dp);
	return dp[ind + 1][n] = max(pick, notpick);
}
int cutRod(vector<int> &cost, int n) {
	// Write your code here.
	vector<int>ar;
	for (int i = 1; i <= n; i++)ar.push_back(i);
	vector<vector<int>>dp(n + 1, vector<int>(n + 1, -1));
	return code(ar, cost, n, 0, dp);
}
// tabulatio approach
