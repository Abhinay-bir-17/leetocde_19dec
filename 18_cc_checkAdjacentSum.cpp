#include <bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for(auto i = (a); i < (b); ++i)
#define FORD(i,a,b) for(int i = (a); i >= (b); --i)
#define RI0n(i,n) FOR(i,0,(n))
#define RI1n(i,n) FOR(i,1,(n))
#define RI0n1(i,n) FOR(i,0,(n)-1)
#define RDn10(i,n) FORD(i,(n)-1,0)
// #define push_back pb;
typedef long long ll;
typedef vector<int> vi;
const ll inf = 1e9 + 7;
const int M = 1e9 + 7;
const int N = 1e5 + 10;
ll fact[N];
void code() {
	// string s; cin >> s;
	// unordered_map<char, int> mp;
	// unordered_map<char, int>ar;

	// int n = s.length();
	// int maxi = 0; char prev;
	// RI0n(i, n) {
	// 	mp[s[i]] += 1;
	// 	if (i == 0) {
	// 		prev = s[i];
	// 		maxi = 1; ar[s[i]] = 1;
	// 	}
	// 	else {
	// 		if (s[i] == prev) {
	// 			maxi += 1; ar[s[i]] = max(ar[s[i]], maxi);
	// 		} else {
	// 			maxi = 1; prev = s[i];
	// 		}
	// 	}
	// }
	// ar[s[n - 1]] = max(maxi, ar[s[n - 1]]);
	// // find the difference between total occurence - max consectuive occurence
	// int ans = INT_MAX;
	// for (auto it : mp) {
	// 	if (it.second == 1) { cout << "0" << endl; return;}
	// 	ans = min( it.second - ar[it.first], ans);
	// }
	// cout << ans << endl;
	int n, q; cin >> n >> q;
	ll sum = 0;
	// inserting el nd finding the 2 largest nd smallest no's
	vi ar; RI0n(i, n) {
		int temp; cin >> temp; ar.push_back(temp);
		sum += temp;
	} sum += sum;
	while (q--) {
		int x; cin >> x; int f = 0;
		for (int i = 0; i < n - 1; i++) {
			for (int j = i + 1; j < n; j++) {
				if ((ar[i] + ar[j]) == (sum - x)) {
					swap(ar[0], ar[i]); swap(ar[n - 1], ar[j]); f = 1; break;
				}
			} if (f)break;
		}
		if (!f)cout << "-1";
		else {
			RI0n(i, n) {cout << ar[i] << " ";}
		} cout << endl;
	}
}// try the code on the test cases of cc
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int t; cin >> t;
	while (t--)
		code();
}