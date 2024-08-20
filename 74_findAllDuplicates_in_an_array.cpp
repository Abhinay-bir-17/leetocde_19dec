class Solution {
public:
	vector<int> findDuplicates(vector<int>& ar) {
		int n  = ar.size();
		int k = n ;
		vector<int> ans = {};
		for (int i = 0; i < n; i++) {
			if (ar[i] > 0) {
				if (ar[ar[i] - 1] > 0)ar[ar[i] - 1] = ar[ar[i] - 1] - k;
				else {
					ans.push_back(ar[i]);
				}
			} else {
				int temp = ar[i] + k;
				if (ar[temp - 1] > 0)ar[temp - 1] = ar[temp - 1] - k;
				else ans.push_back(temp);
			}
		} return ans;
	}
};