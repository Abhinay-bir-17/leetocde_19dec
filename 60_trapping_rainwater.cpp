class Solution {
public:
	int trap(vector<int>& ar) {
		int n = ar.size();
		vector<int> left(n);
		vector<int> right(n);
		int temp = -1;
		for (int i = 0; i < n; i++) {
			if (temp < ar[i])temp = ar[i];
			left[i] = temp;
		} temp = -1;
		for (int i = n - 1; i >= 0; i--) {
			if (temp < ar[i])temp = ar[i];
			right[i] = temp;
		}
		int ans = 0;
		for (int i = 0; i < n; i++) {
			ans += min(left[i], right[i]) - ar[i];
		} return ans;
	}
};