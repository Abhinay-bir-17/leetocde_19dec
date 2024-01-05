
// brute force solution
class Solution {
public:
	int sumOddLengthSubarrays(vector<int>& ar) {
		int n = ar.size();

		int ans = 0;
		for (int i = 0; i < n; i++) {
			int sum = 0;
			for (int j = i; j < n; j++) {
				sum += ar[j];
				if ( (j - i + 1) & 1)ans += sum;
			}
		} return ans;
	}
};