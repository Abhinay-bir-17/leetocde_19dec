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
	int n, ind; cin >> n >> ind;
	vi ar;
	ind -= 1;
	RI0n(i, n) {
		int temp; cin >> temp; ar.push_back(temp);
	}
	int ans = 0;
	if (ar[ind] == 1)ans += 1;
	int l = ind - 1, r = ind + 1;
	while ( l >= 0 || r < n) {
		if ( l >= 0 && r < n && ar[l] == 1 && ar[r] == 1) {ans += 2; l -= 1; r += 1;}
		else if ( l < 0 && r < n && ar[r] == 1) {ans += 1; r += 1;}
		else if ( r >= n && l >= 0 & ar[l] == 1) {ans += 1; l -= 1;}
		else if ( l < 0 && r >= n)break;
		// else if( l>=0 && r<n && ar[r]==ar[l]==0){l-=1; r-=1;}
		else {l -= 1; r += 1;}
	}
	cout << ans << endl;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	// int t; cin >> t;
	// while (t--)
	code();
}