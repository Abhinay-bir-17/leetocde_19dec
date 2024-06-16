int numberOfSubstrings(string s) {
	int n = s.length();
	if (n < 3)return 0;
	int l = 0, r = 2;
	unordered_map<char, int>mp;
	mp[s[0]] += 1;
	mp[s[1]] += 1; int ans = 0;
	while (r < n) {
		mp[s[r]] += 1;
		if (mp['a'] == 1 && mp['b'] == 1 && mp['c'] == 1) {
			ans +=  n - 2;
		}
		mp[s[l]] -= 1;
		l += 1;
		r += 1; 1
	} return ans;
}