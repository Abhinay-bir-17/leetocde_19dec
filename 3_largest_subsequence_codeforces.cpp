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
	int n; cin >> n;
	string s; cin >> s;
	string lex = "";
	// find lexio largest subseq ,
	// also check if its already sorted

	// cout << "n is:" << n << endl;
	int pos = -1;
	vi v; int unique_lett = 0;
	while (pos < (n - 1)) {
		// cout << "pos is:" << pos << endl;
		char x = 'A';
		int l = pos + 1;  //  ababba
		for (int i = pos + 1; i < n; i++) {
			if (x <= s[i]) {
				x = s[i];
				pos = i;
			}
		}
		// unique_lett += 1;
		// cout << "pos is:" << pos << endl;
		// cout << "x is:" << x << endl;
		for (int i = l; i <= pos; i++ ) {
			if (s[i] == x) {
				v.push_back(i); lex += s[i];
				//	cout << "string ans is now:" << ans << endl;
			}
		}
	}

	// cout << "lex is:" << lex << endl;
	// what if the lex is already sorted
	int f = 1;
	for (int i = 0; i < lex.length() - 1; i++) {
		if (lex[i] > lex[i + 1]) {f = 0; break;}
	}
	if (f) { // if lex is sorted
		int flag = 1;
		for (int i = 0; i < s.length() - 1; i++) {
			if (s[i] > s[i + 1]) {flag = 0; break;}
		}
		if (flag)cout << "0" << endl; else cout << "-1" << endl;
		return;
	}
	// count no of times 1st letter is repeated
	char x = lex[0]; unique_lett = 1;
	for (int i = 1; i < lex.length(); i++) {if (x == lex[i])unique_lett += 1;}
	// rotate right n-1 times
	n = v.size();
	for (int l = 0, r = n - 1; l <= r; ) {
		char x = s[v[l]]; s[v[l]] = s[v[r]]; s[v[r]] = x;
		l += 1; r -= 1;
	}
	// check if its sorted
	f = 1;
	for (int i = 0; i < s.length() - 1; i++) {
		if (s[i] > s[i + 1]) {f = 0; break;}
	}
	if (f)cout << n - unique_lett << endl; else cout << "-1" << endl;
}
int main()
{

	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int t; cin >> t; while (t--)code();
}