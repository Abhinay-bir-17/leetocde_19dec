int totalFruit(vector<int>& ar) {
	int n = ar.size();
	/*so here u have to find longest
	subarray with atmost 2 distinct
	numbers*/
	int l = 0, r = 1;
	int cnt = 1; int ans = 0;
	unordered_map<int, int>mp;
	mp[ar[l]] += 1;
	while (r < n) {
		// focus here bro
		if (mp[ar[r]] == 0) {
			cnt += 1;
		}
		mp[ar[r]] += 1;
		if (cnt > 2) {
			ans = max(ans, r - l);
			while (mp[ar[l]] != 0) {
				mp[ar[l]] -= 1;
				if (mp[ar[l]] == 0) {l += 1; break;}
				l += 1;
			}
			cnt -= 1;
			r += 1;
		} else {
			ans = max(ans, r - l + 1); r += 1; // lol
		}
	}	return ans;
}
