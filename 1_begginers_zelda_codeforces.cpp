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
	vi ar(n + 1, 0);
	RI0n(i, n - 1) {
		int u, v; cin >> u >> v;
		ar[u] += 1; ar[v] += 1;
	} int ans = 0;
	for (int i = 1; i <= n; i++) {
		if (ar[i] == 1)ans += 1;
	}
	ans += 1;
	cout << ans / 2 << endl;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int t; cin >> t;
	while (t--)code();

}