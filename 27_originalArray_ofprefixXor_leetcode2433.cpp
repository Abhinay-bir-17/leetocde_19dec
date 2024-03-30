class Solution {
public:
	vector<int> findArray(vector<int>& ar) {
		int n = ar.size();
		vector<int> dp; dp.push_back(ar[0]);
		for (int i = 1; i < n; i++) {
			dp.push_back( ar[i - 1]^ar[i]);
		} return dp;
	}
};