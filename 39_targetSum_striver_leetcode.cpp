// recursion
class Solution {
public:
	int code(int n, vector<int>&ar, int ind, int sum, int k) {
		if (ind == n) {
			if (sum == k)return 1;
			else return 0;
		}
		return code(n, ar, ind + 1, sum + ar[ind], k) + code(n, ar, ind + 1, sum - ar[ind], k);
	}
	int findTargetSumWays(vector<int>& ar, int k) {
		int n = ar.size();
		return code(n, ar, 0, 0, k);

	}
};
/* this problems can be seen as  s1 -s2 = k, s1 +s2 = ts(total sum), so s1
s1 = (k+ts)/2 , so count no of subsets with sum s1 */
// recursive approach
class Solution {
public:
	int code(vector<int>&ar, int k, int n, int ind, int aux_sum) {
		if (ind == n) {
			if (aux_sum == k)return 1;
			else return 0;
		}
		return code(ar, k, n, ind + 1, aux_sum + ar[ind]) + code(ar, k, n, ind + 1, aux_sum);
	}
	int findTargetSumWays(vector<int>& ar, int k) {
		int n = ar.size();
		int ts = 0; for (int i = 0; i < n; i++)ts += ar[i];
		if (k & 1) {
			if (ts % 2 == 0)return 0;
		} else {
			if (ts & 1)return 0;
		}
		k = (ts - k) / 2;
		return code(ar, k, n, 0, 0);
	}
};


// rec + memo approach
class Solution {
public:
	int code(vector<int>&ar, int k, int n, int ind, int aux_sum, vector<vector<int>>&dp) {
		if (ind == n) {
			if (aux_sum == k)return 1;
			else return 0;
		}
		if (aux_sum > k)return 0;
		if (dp[ind + 1][k - aux_sum] != -1)return dp[ind + 1][k - aux_sum];
		return dp[ind + 1][k - aux_sum] = code(ar, k, n, ind + 1, aux_sum + ar[ind], dp) + code(ar, k, n, ind + 1, aux_sum, dp);
	}
	int findTargetSumWays(vector<int>& ar, int k) {
		int n = ar.size();
		int ts = 0; for (int i = 0; i < n; i++)ts += ar[i];
		if (k & 1) {
			if (ts % 2 == 0)return 0;
		} else {
			if (ts & 1)return 0;
		}
		k = (ts - k) / 2;
		vector<vector<int>>dp(n + 1, vector<int>(k + 1, -1));
		return code(ar, k, n, 0, 0, dp);
	}
};

// tabulation approach :