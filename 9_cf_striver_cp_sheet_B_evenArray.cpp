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
void code2() {
	int n; cin >> n; int odd = 0, even = 0; int ans = 0; int flag = 1;
	RI0n(i, n) {
		int temp; cin >> temp;
		if ( (i & 1) && (temp % 2 == 0)) {odd += 1; flag = 0;}
		if (  !(i & 1) && (temp & 1)) {even += 1; flag = 0;}

		if (odd > 0 && even > 0) {ans += 1; odd -= 1; even -= 1;}


	}
	if (flag)cout << "0";
	else {
		if (odd != 0 || even != 0)cout << "-1"; else cout << ans;
	} cout << endl;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int t; cin >> t;
	while (t--)
		code2();
}