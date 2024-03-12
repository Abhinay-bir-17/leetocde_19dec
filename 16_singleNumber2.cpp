class Solution {
public:
	int singleNumber(vector<int>& ar) {
		int n = ar.size();
		int count = 0;
		int ans = 0;
		while (count < 32) {
			int setbit = 0;
			for (int i = 0; i < n; i++) {
				if (ar[i] & 1)setbit += 1;  ar[i] = ar[i] >> 1;
			}
			if (setbit % 3 != 0)ans += (1 << count); count += 1;
		} return ans;
	}
};