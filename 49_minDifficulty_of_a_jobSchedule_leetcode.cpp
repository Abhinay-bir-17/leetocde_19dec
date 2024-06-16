// recursion works: 20th may 24
class Solution {
public:
	int code(int lv, int ind, vector<int>&ar, int d, int n) {
		if (d == 1) {

			for (int i = ind; i < n; i++) {
				lv = max(lv, ar[i]);
			} return lv;
		}
		int a = INT_MAX, b = INT_MAX;
		if ( ind <= (n - d)) {
			a = code( max(lv, ar[ind]), ind + 1, ar, d, n);
		}
		b = lv + code(ar[ind], ind + 1, ar, d - 1, n);
		return min(a, b);
	}
	int minDifficulty(vector<int>& ar, int d) {
		int n = ar.size();
		if (n < d)return -1;
		return code(ar[0], 1, ar, d, n);
	}
};
// rec + memo of 20th may 2024
class Solution {
public:
	int code(int lv, int ind, vector<int>&ar, int d, int n, vector<vector<int>>&dp) {
		if (d == 1) {

			for (int i = ind; i < n; i++) {
				lv = max(lv, ar[i]);
			} return lv;
		}
		if (dp[ind + 1][d] != -1)return dp[ind + 1][d];
		int a = INT_MAX, b = INT_MAX;
		if ( ind <= (n - d)) {
			a = code( max(lv, ar[ind]), ind + 1, ar, d, n, dp);
		}
		b = lv + code(ar[ind], ind + 1, ar, d - 1, n, dp);
		return dp[ind + 1][d] = min(a, b);
	}
	int minDifficulty(vector<int>& ar, int d) {
		int n = ar.size();
		if (n < d)return -1;
		vector<vector<int>>dp(n + 1, vector<int>(d + 1, -1));
		return code(ar[0], 1, ar, d, n, dp);
	}
};

// rec
class Solution {
public:
	int code( int ind, int lv, int d, vector<int>&ar, int n) {
		// cout << "ind is:" << ind << ",d is:" << d << ",lv is:" << lv << endl;
		if (ind == n) {
			//cout << "lv in ind==n is:" << lv << endl;
			return lv;
		}
		if (d == 0) {
			for (int i = ind; i < n; i++)lv = max(lv, ar[i]); return lv;
			// cout << "lv is in d==0:" << lv << endl;
		}
		// pick the element
		int a  = INT_MAX, b = INT_MAX;
		if ((n - ind - 1) >= d) a = code(ind + 1, max(lv, ar[ind]), d, ar, n);
		// do not pick the element
		b = lv + code(ind + 1, ar[ind], d - 1, ar, n);
		// cout << "a :" << a << ",b:" << b << endl;
		return min(a, b);
	}
	int minDifficulty(vector<int>& ar, int d) {
		int n = ar.size();
		if (n < d)return -1;
		//  1th ind, min=ar[0]
		int ans = 0;
		ans = code(1, ar[0], d - 1, ar, n); return ans;
	}
};

// rec + memo
class Solution {
public:
	int code( int ind, int lv, int d, vector<int>&ar, int n, vector<vector<int>>&dp) {
		// cout << "ind is:" << ind << ",d is:" << d << ",lv is:" << lv << endl;
		if (ind == n) {// if last el is the only job for the dth day
			//cout << "lv in ind==n is:" << lv << endl;
			return lv;
		}
		if (dp[ind][d] != -1)return dp[ind][d];
		if (d == 0) {// if d becomes 0 in middle of arry i.e left to last el
			for (int i = ind; i < n; i++)lv = max(lv, ar[i]); return lv;
			// cout << "lv is in d==0:" << lv << endl;
		}
		// pick the element
		int a  = INT_MAX, b = INT_MAX;
		if ((n - ind - 1) >= d) a = code(ind + 1, max(lv, ar[ind]), d, ar, n, dp);
		// do not pick the element
		b = lv + code(ind + 1, ar[ind], d - 1, ar, n, dp);
		// cout << "a :" << a << ",b:" << b << endl;
		return dp[ind][d] = min(a, b);
	}
	int minDifficulty(vector<int>& ar, int d) {
		int n = ar.size();
		if (n < d)return -1;
		//  1th ind, min=ar[0]
		int ans = 0;
		vector<vector<int>>dp(n, vector<int>(d, -1));
		ans = code(1, ar[0], d - 1, ar, n, dp); return ans;
	}
};

// lets gooo
#include<bits/stdc++.h>
typedef long long ll;
const int M = 1e9 + 7;
int firstElement(int n) {
	// code here abhinay bir you can do it
	ll a = 1, b = 1, c = 1, d = 0;

	vector < vector<ll>dp(2, vector<ll>(4, 0));
	dp[0][0] = a; dp[0][1] = b; dp[0][2] = c; dp[0][3] = d;
	for (ll i = 2; i <= n; i++) {
		dp[1][0] = (dp[0][0] * a + (dp[0][1] * c)) % M;
		dp[1][1] = (dp[0][0] * b + (dp[0][1] * d)) % M;
		dp[1][2] = (dp[0][2] * a + dp[0][3] * c) % M;
		dp[1][3] = (dp[0][2] * b + dp[0][3] * d) % M; // focus abhinay bir you can do it!!!
		for (int i = 0; i < 4; i++)cout << dp[i] << " "; cout << endl;

		for (int i = 0; i < 1; i++) {
			for (int j = 0; j < 4; j++)dp[i][j] = dp[1][j];
		}
	}
	return (dp[1][2]) % (M);
}