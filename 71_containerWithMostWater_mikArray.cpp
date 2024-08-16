class Solution {
public:
	int maxArea(vector<int>& ar) {
		int n = ar.size();
		int l = 0, r = n - 1;
		int ans = INT_MIN;
		while (l < r) {
			int temp = min(ar[l], ar[r]) * (r - l);
			if (temp > ans) ans = temp;
			if (ar[l] < ar[r])l += 1;
			else if (ar[l] > ar[r])r -= 1;
			else {
				if (ar[l + 1] > ar[r - 1])l += 1;
				else r -= 1;
			}
		} return ans;
	}
};