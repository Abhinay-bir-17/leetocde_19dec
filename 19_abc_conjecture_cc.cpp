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
	int n ; cin >> n;
	string a, b; cin >> a >> b;
	int n_a = 0	, n_b = 0;
	int ae = 0;
	for (int i = 0; i < n; i++) {
		// cout << "a[i] is:" << a[i] << ", b[i] is:" << b[i] << endl;
		if (a[i] == 'a') {
			if (b[i] == 'b') {cout << "no" << endl; return;}
			if (b[i] == 'c')ae += 1;
		}
		else if (a[i] == 'b') {
			if (b[i] != 'b') {cout << "no" << endl; return;}
			n_a += ae; ae = 0;
		} else {
			if (b[i] == 'b') {cout << "no" << endl; return;}
			if (b[i] == 'a') {
				if (n_a == 0) {cout << "no" << endl; return;}
				else {n_a -= 1; n_b -= 1;}
			}
		}
	}
	if (n_a > 0 || ae > 0 )cout << "no";
	else cout << "yes";
	cout << endl;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int t; cin >> t;
	while (t--)
		code();
}
