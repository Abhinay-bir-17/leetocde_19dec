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
	int temp = s.length();
	temp = temp / 2;

	for (int i = 0; i < n; i++) {
		if ( (n - i - 1) > temp) {
			cout << 'P';
			if ( s[i] == 'R')temp -= 1;
		}
		else {
			if (s[i] == 'P')cout << 'S';
			else if (s[i] == 'R')cout << 'P';
			else cout << 'R';
		}
	} cout << endl;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int t; cin >> t;
	while (t--)code();

}