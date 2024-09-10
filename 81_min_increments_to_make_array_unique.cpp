class Solution {
public:
	int minIncrementForUnique(vector<int>& ar) {
		int n = ar.size();
		sort(ar.begin(), ar.end());
		int ans = 0;
		for (int i = 1; i < n; i++) {
			if (ar[i] <= ar[i - 1]) {ans += ar[i - 1] - ar[i] + 1; ar[i] = ar[i - 1] + 1;}
		}        return ans;
	}
};

//----> 3,2,1,2,1,7  :

class Solution {
public:
	int minIncrementForUnique(vector<int>& ar) {
		unordered_map<int, int> mp;
		int n = ar.size(); int ma  = INT_MIN;
		for (int i = 0; i < n; i++) {
			mp[ar[i]] += 1;
			ma = max(ma, ar[i]);
		} int cnt = 0;
		for (int i = 0; i <= ma; i++) {
			if (mp[i] > 1) {
				cnt += mp[i] - 1;
				mp[i + 1] += mp[i] - 1;
			}
		}
		int flag = 1; ma += 1;
		while (flag) {
			if (mp[ma] > 1) { mp[ma + 1] += mp[ma] - 1; cnt += mp[ma] - 1; ma += 1;}
			else flag = 0;

		}
		return cnt;
	}
};