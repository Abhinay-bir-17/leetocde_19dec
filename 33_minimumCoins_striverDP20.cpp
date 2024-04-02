// recusrion approach
#include <bits/stdc++.h>
int code(vector<int>ar, int x, int n, int ind) {
	if (x == 0)return 0;
	if (ind == n)return 0;
	int pick = -1, notpick = -1;
	if (ar[ind] <= x)pick = 1 + code(ar, x - ar[ind], n, ind);
	else notpick = code(ar, x, n, ind + 1);
	return max(pick, notpick);
}
int minimumElements(vector<int> &ar, int x) {
	// Write your code here bruhhh
	int n = ar.size();
	sort(ar.begin(), ar.end(), greater<int>());
	return code(ar, x, n, 0);
}