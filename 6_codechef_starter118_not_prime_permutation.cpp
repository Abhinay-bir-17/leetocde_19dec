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
	vi v;
	RI0n(i, n) {int temp; cin >> temp; v.push_back(temp);}
	if (n <= 2) {cout << "-1" << endl; return;}
	for (int i = 0; i < n; i++) {
		if (v[i] == 1)cout << '3' << " ";
		else if (v[i] == 3)cout << '1' << " ";
		else cout << v[i] << " ";
	} cout << endl;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int t; cin >> t;
	while (t--)code();
}