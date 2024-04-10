// biweekly contest 127
class Solution {
public:
	int minimumSubarrayLength(vector<int>& ar, int k) {
		int max_len = 0;
		int ans = 0;
		int n = ar.size();
		vector<int>br(32, 0);// bit count vector
		int aux_or = 0;
		for (int l = 0, r = 0; r < n;) {
			aux_or = (aux_or | ar[r]); // focus abhinay bir you can do it okay????
			int temp = ar[r]; int ind = 0;
			while (temp) {
				if (temp & 1) {
					br[ind] += 1;
				}
				ind += 1;
				temp = temp >> 1;
			}
			if (aux_or <= k) {max_len += 1; ans = max(ans, max_len); r += 1;}
			else {
				// now we have to reverse the or oprn of lth posn no
				int temp = ar[l]; ind = 0;
				while (temp) {
					if (temp & 1) {
						br[ind] -= 1;
						if (br[ind] == 0) {
							aux_or = (aux_or & (~(1 << ind)));
						}
					}
					ind += 1;
					temp = temp >> 1;
				} l += 1; r += 1; max_len -= 1; // inside else
			}
		} if (ans == 0)return -1; else return ans;
	}
};

// copied again
// biweekly contest 127
class Solution {
public:
	int minimumSubarrayLength(vector<int>& ar, int k) {
		int ans = INT_MAX;
		int n = ar.size();
		vector<int>br(32, 0);// bit count vector
		int aux_or = 0;
		for (int l = 0, r = 0; r < n;) {
			if (ar[r] >= k) {return 1;}
			aux_or = (aux_or | ar[r]); // focus abhinay bir you can do it okay????
			int temp = ar[r]; int ind = 0;
			while (temp) {
				if (temp & 1) {
					br[ind] += 1;
				}
				ind += 1;
				temp = temp >> 1;
			} cout << "aux_or is:" << aux_or << endl;
			if (aux_or < k) { r += 1;}
			else {
				ans = min(r - l + 1, ans);
				if (ans == 1) {return 1;}
				// now we have to reverse the or oprn of lth posn no
				int temp = ar[l]; ind = 0;
				cout << "temp is:" << temp << endl;
				while (temp) {
					cout << "temp in while:" << temp << endl;
					if (temp & 1) {
						cout << "ind is:" << ind << endl;
						br[ind] -= 1;
						cout << "br[ind]:" << br[ind] << endl;
						if (br[ind] == 0) {
							aux_or = (aux_or & (~(1 << ind)));
						}
					}
					ind += 1;
					temp = temp >> 1;// ans gets updated only in else part  ,m,m
				}
				cout << "aux_or inside else is:" << aux_or << endl;
				l += 1; // inside else
			} cout << "ans is:" << ans << endl;
		} if (ans == INT_MAX)return -1; else return ans;
	}
};