#include <bits/stdc++.h>
void fastscan(int &number)
{	bool negative = false;
	register int c;
	number = 0;
	c = getchar();
	if (c == '-')
	{	negative = true;
		c = getchar();
	} for (; (c > 47 && c < 58); c = getchar())
		number = number * 10 + c - 48;
	if (negative)
		number *= -1;
}
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
	ll n; cin >> n;
	// ll ans = 0;
	if (n & 1) { // no of odd numbers form 1 to temp
		// for (ll i = 1;  ; i += 2) {
		// 	ll temp = i * i;
		// 	if (temp <= n)ans += 1;
		// 	else break;
		// }
		ll temp = ll(sqrtl(n));
		// cout << "temp is:" << temp << endl;
		if (temp & 1)cout << ll(temp / 2) + 1;
		else cout << ll(temp / 2);
	} else { // no of even nos from 1 to temp
		ll temp =  ll(sqrtl(n));
		// cout << "temp is:" << temp << endl;
		cout << ll(temp / 2);
	}
	cout <<  endl;
}
int main()
{
#ifndef ONLINE_JUDGE
	//for getting input from input.txt
	freopen("input_2023.txt", "r", stdin);
	//for writing output to output.txt
	freopen("output_2023.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int t; cin >> t; while (t--)code();
}