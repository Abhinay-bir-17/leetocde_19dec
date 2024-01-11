#include <bits/stdc++.h>
// void fastscan(int &number)
// {	bool negative = false;
// 	register int c;
// 	number = 0;
// 	c = getchar();
// 	if (c == '-')
// 	{	negative = true;
// 		c = getchar();
// 	} for (; (c > 47 && c < 58); c = getchar())
// 		number = number * 10 + c - 48;
// 	if (negative)
// 		number *= -1;
// }
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
	string s; cin >> s;
	string ans = "";
	int n = s.length();
	// cout << "n is:" << n << endl;
	int pos = -1;
	vi v;
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
		// cout << "pos is:" << pos << endl;
		// cout << "x is:" << x << endl;
		for (int i = l; i <= pos; i++ ) {
			if (s[i] == x) {
				ans = ans + x;
				//	cout << "string ans is now:" << ans << endl;
			}
		}
	}
	cout << ans << endl;
}
int main()
{
// #ifndef ONLINE_JUDGE
// 	//for getting input from input.txt
// 	freopen("input_2023.txt", "r", stdin);
// 	//for writing output to output.txt
// 	freopen("output_2023.txt", "w", stdout);
// #endif
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	// int t; cin >> t; while (t--)
	code();
}