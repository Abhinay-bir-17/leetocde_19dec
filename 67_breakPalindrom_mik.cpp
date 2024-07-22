// test cases like aa, aba
class Solution {
public:
	string breakPalindrome(string ar) {
		int n  = ar.length();
		// check if 1 char is in ar only
		int f = 1;
		for (int i = 1; i < n; i++) {
			if (ar[i] != ar[i - 1]) {f = 0; break;}
		}
		if (f) {
			if (ar[0] == 'a') {
				if (n == 1)return "";
				else ar[n - 1] = 'b';
			}
			else {
				if (n == 1)return "";
				else ar[0] = 'a';
			} return ar;
		}
		// if more than 1 char is present in ar
		f = 1;
		for (int i = 0; i < n / 2; i++) {
			if (ar[i] != 'a') {
				f = 0; ar[i] = 'a'; break;
			}
		}
		if (f) {
			ar[n - 1] = 'b';

		} return ar;
	}
};