// this is using nlogn
class Solution {
public:
	int longestConsecutive(vector<int>& ar) {
		int n = ar.size();
		if (n == 0)return 0;
		sort(ar.begin(), ar.end());
		int ans = 1;
		// lionel messi u can do it okkkkkkkkkkkay
		for (int i = 0, j = 1; j < n; j++) {
			if (ar[j] == (ar[j - 1] + 1)) {
				ans = max(ans, ar[j] - ar[i] + 1);
			} else if (ar[j] == ar[j - 1]) {

			} else {
				i = j;
			}
		} return ans;

	}
};

// linear time complexity approach
class Solution {
public:
	int longestConsecutive(vector<int>& ar) {
		int n = ar.size(); if (n == 0)return 0;
		unordered_map<int, int>mp;
		for (int i = 0; i < n; i++)mp[ar[i]] = 1;
		int ans = 1;
		for (int i = 0; i < n; i++) {
			int cnt = 1;
			if (mp[ar[i] + 1] == 0) {
				for (int j = 1;; j++)if (mp[ar[i] - j]) {cnt += 1; ans = max(ans, cnt);} else break;
			}
		} return ans;
	}
};