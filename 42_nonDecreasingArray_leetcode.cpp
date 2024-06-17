// my optimized soln of 17th june 24
class Solution {
public:
	bool checkPossibility(vector<int>& ar) {
		int n = ar.size();
		if (n <= 2)return true;
		int cnt = 0;
		if (ar[0] > ar[1]) { ar[0] = ar[1]; cnt += 1;}
		for (int i = 1; i < n - 1; i++) {
			if (ar[i] < ar[i - 1]) {
				if (ar[i + 1] < ar[i])return false;/*if 3 els r in striclty
				decreasin order*/
				else if (ar[i + 1] >= ar[i - 1]) {ar[i] = ar[i - 1]; cnt += 1;}
				else if (ar[i + 1] < ar[i - 1]) {
					if (ar[i] >= ar[i - 2])ar[i - 1] = ar[i];// decrease
					// above line is for -1 4 2 3
					else ar[i] = ar[i - 1]; cnt += 1;// increase, ex:3 4 2 3
					// so increase 2 to 4
				}
			}
			if (cnt > 1)return false;
		}
		if (ar[n - 1] < ar[n - 2])cnt += 1;
		if (cnt > 1)return false; return true;
	}
};

//
class Solution {
public:
	bool checkPossibility(vector<int>& ar) {
		int n = ar.size();
		int cnt = 0;
		if (n <= 2)return true;
		for (int i = 1; i < n; i++) {
			if ((i + 1) < n) {
				if ( ar[i] < ar[i - 1]) {
					if (ar[i + 1] < ar[i]) {return false;}
					else if (ar[i + 1] == ar[i] && n != 3) {
						if (i > 1)if (ar[i - 2] > ar[i]) {return false;} // 1 2 5 3 3, we can decease
						// 5 to 2
					}// 4 2 2
					else { // ar[i+1]> ar[i]
						if (ar[i + 1] < ar[i - 1] && n != 3) {
							if (i > 1)if (ar[i - 2] > ar[i]) {return false;} // -1 4 2 3
						} // 4 2 3
					}
					cnt += 1;
					cout << "ar[i] is:" << ar[i] << ", cnt:" << cnt << endl;
					if (cnt > 1)return false;
				}// else ar[i]>=ar[i-1] so no need to do any oprn
			}
		}
		// check last index
		if (ar[n - 1] < ar[n - 2])cnt += 1;
		if (cnt > 1)return false; return true;
	}
};

// neetcode soln
class Solution {
public:
	bool checkPossibility(vector<int>& ar) {
		int n = ar.size(); int cnt = 0;
		if (n <= 2)return true;
		for (int i = 0; i < n - 1; i++) {
			if (ar[i] > ar[i + 1]) {
				if ( i == 0 || ar[i + 1] >= ar[i - 1] )ar[i] = ar[i + 1];
				else ar[i + 1] = ar[i];
				cnt += 1;
				if (cnt > 1)return false;
			}
		} return true;
	}
};
//