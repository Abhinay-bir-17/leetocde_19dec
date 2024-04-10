// recursion
class Solution {
public:
	int code(vector<int>ar, int n, int k, int ind, int aux_sum) {
		if (aux_sum == k)return 1; //did this no 0 will be in ar vector
		if (ind == n) {
			return 0;
		}
		if (aux_sum > k)return 0;
		int pick = 0, notpick = 0;
		if (ar[ind] <= (k - aux_sum)) {
			pick = code(ar, n, k, ind, aux_sum + ar[ind]);
		}
		notpick = code(ar, n, k, ind + 1, aux_sum);
		return pick + notpick;
	}
	int change(int k, vector<int>& ar) {
		int n = ar.size();
		return code(ar, n, k, 0, 0);
	}
};

// rec + memo
// recursion
class Solution {
public:
	int code(vector<int>ar, int n, int k, int ind, int aux_sum, vector<vector<int>>&dp) {
		if (aux_sum == k)return 1; //did this no 0 will be in ar vector
		if (ind == n) {
			return 0;
		}
		if (aux_sum > k)return 0;
		if (dp[ind + 1][k - aux_sum] != -1)return dp[ind + 1][k - aux_sum];
		int pick = 0, notpick = 0;
		if (ar[ind] <= (k - aux_sum)) {
			pick = code(ar, n, k, ind, aux_sum + ar[ind], dp);
		}
		notpick = code(ar, n, k, ind + 1, aux_sum, dp);
		return dp[ind + 1][ k - aux_sum] = pick + notpick;
	}
	int change(int k, vector<int>& ar) {
		int n = ar.size();
		vector<vector<int>>dp(n + 1, vector<int>(k + 1, -1));
		return code(ar, n, k, 0, 0, dp);
	}
};

// tabulation approach:
