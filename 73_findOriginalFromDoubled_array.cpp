class Solution {
public:
	vector<int> findOriginalArray(vector<int>& ar) {
		int n = ar.size();
		if (n & 1) {return {};}
		sort(ar.begin(), ar.end());
		int i = 0, j = 1;
		int cnt = 0;
		while (j < n) {

			while (ar[i] == -1)i += 1;
			if (i == j)j += 1;
			if ((ar[i] * 2) == ar[j])
			{i += 1; ar[j] = -1; j += 1; cnt += 1;}
			else j += 1;
			// cout << "cnt:" << cnt << ",i:" << i << ",j:" << j << endl;
		}
		if (cnt != (n / 2))return {};
		vector<int> ans;
		for (int i = 0; i < n; i++) {
			if (ar[i] != -1)ans.push_back(ar[i]);
			// else cnt += 1;
		}
		return ans;
	}
};