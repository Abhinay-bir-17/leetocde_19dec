// think abt [[1,5],[3,4]]
class Solution {
public:
	int maxDistance(vector<vector<int>>& ar) {
		int n = ar.size(); // no of arrays
		int mi = ar[0][0], ma = ar[0][ar[0].size() - 1];
		cout << "mi:" << mi << ",ma:" << ma << endl;

		if ( abs(mi - ar[1][ar[1].size() - 1]) > abs(ar[1][0] - ma))
			ma = ar[1][ar[1].size() - 1];
		else mi = ar[1][0];
		cout << "mi:" << mi << ",ma:" << ma << endl;

		for (int i = 2; i < n; i++) {
			// if both are wider
			if ( mi > ar[i][0] && ma < ar[i][ar[i].size() - 1]) {
				if ( abs(mi - ar[i][ar[i].size() - 1]) > abs(ma - ar[i][0]))
					ma = ar[i][ar[i].size() - 1];
				else mi = ar[i][0];
			} else if ( mi > ar[i][0])mi = ar[i][0];
			else if (ma < ar[i][ar[i].size() - 1]) ma = ar[i][ar[i].size() - 1];
			cout << "mi:" << mi << ",ma:" << ma << endl;
		} return abs(mi - ma);
	}
};