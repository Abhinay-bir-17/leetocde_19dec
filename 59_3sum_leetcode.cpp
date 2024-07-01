// this gives tle : brute force approach with mild optmi to run faster
class Solution {
public:
	vector<vector<int>> threeSum(vector<int>& ar) {
		vector<vector<int>> ans;
		int n =     ar.size();
		sort(ar.begin(), ar.end());
		for (int i = 0; i <= (n - 3); i++) {
			// focus abhinay
			if (i > 0 && ar[i] == ar[i - 1 ])continue;
			for (int j = i + 1; j <= n - 2; j++) {
				if (j > (i + 1) && ar[j] == ar[j - 1])continue;
				for (int k = j + 1; k <= n - 1; k++) {
					if ( (ar[i] + ar[j] + ar[k]) > 0)break;
					if (k > (j + 1) && ar[k] == ar[k - 1])continue;
					if ( (ar[i] + ar[j] + ar[k]) == 0) {
						vector<int>temp;
						temp.push_back(ar[i]); temp.push_back(ar[j]); temp.push_back(ar[k]);
						ans.push_back(temp);
					}
				}
			}

		}
		return ans;
	}
};
// approach suing 2 sum loigc,  a + b = -c ........... ............
class Solution {
public:
	vector<vector<int>> threeSum(vector<int>& ar) {
		int n = ar.size();
		sort(ar.begin(), ar.end());
		vector<vector<int>>ans;
		for (int i = 0; i <= (n - 3); i++) {
			if (i > 0 && ar[i] == ar[i - 1])continue;
			int l = i + 1, r = n - 1;
			int sum = -1 * ar[i];
			while (l < r) {
				while ( (r != (n - 1)) && (ar[r] == ar[r + 1])) {
					r -=  1;
					if (r <= l)break; // for inputs like [-2,0,0,2,2]
				} // [0,0,0,0......0]
				// l nd r  are both 1 nd sum = 2
				if (r <= l)break;
				while ( ((l - 1) != i) && (ar[l] == ar[l - 1]))l += 1;
				if (l >= r)break;
				if ((ar[l] + ar[r]) > sum) r -= 1;
				else if ((ar[l] + ar[r]) < sum)l += 1;
				else {

					vector<int>temp; temp.push_back(ar[i]);
					temp.push_back(ar[l]); temp.push_back(ar[r]);
					l += 1; r -= 1; ans.push_back(temp);
				}
			}
		} return ans;
	}
};