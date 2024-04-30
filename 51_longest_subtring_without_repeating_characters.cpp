int lengthOfLongestSubstring(string s) {
	int n = s.length();
	if (n == 0)return 0;
	// wht the fuk abhinay bir, you can do it
	unordered_map<char, int> mp;
	int l = 0, r = 1;
	int ans = 1;
	mp[s[l]] += 1;
	while (r < n) {
		if (mp[s[r]] == 1) {
			if (s[l] == s[r]) {
				l += 1;
				r += 1;// this line is cool af
			} else {
				mp[s[l]] -= 1; l += 1;
			}

		} else if (mp[s[r]] == 0) {
			mp[s[r]] += 1;
			if (ans < (r - l + 1))ans = r - l + 1;
			r += 1;

		}

		if (l == r)r += 1;
	} return ans;
}