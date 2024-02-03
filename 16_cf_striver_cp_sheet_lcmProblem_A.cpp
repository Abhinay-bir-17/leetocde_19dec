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
	ll n; cin >> n;
	ll cnt = 0;
	while (n > 9) {
		ll sum = 0;
		ll temp = n;
		while (temp != 0) {
			sum += temp % 10; temp = temp / 10;
		}
		n = sum;
		cnt += 1;
	}
	cout << cnt << endl;
}
void code1() {
	int n; cin >> n;
	int ans = INT_MAX;
	int a, b;
	for (int i = 0; i <= n; i++) {
		if (   (i ^ n) <= n) {
			int temp = i ^ n;
			if ( abs(i - temp) < ans) {
				ans = abs(i - temp);
				a = i; b = temp;
			}
		}
		if ( ans == 2)break;
	}
	cout << a << " " << b << endl;
}
void code2() {
	int n, l; cin >> n >> l; //vi ar;
	vector<float> ar;
	RI0n(i, n) {int temp; cin >> temp; ar.push_back(temp);}
	sort(ar.begin(), ar.end());
	float ans = INT_MIN;
	if (ar[0] != 0)ans = max(ar[0] - 0, ans);
	if (ar[n - 1] != n)ans = max(l - ar[n - 1], ans);
	for (int i = 1; i < n; i++)ans = max(ans, float((ar[i] - ar[i - 1]) / 2));
	cout << ans << endl;

}
void code3() {
	ll l, r; cin >> l >> r;
	ll temp = 2 * l;
	if (temp <= r) {
		cout << l << " " << temp;
	} else {
		cout << "-1" << " " << "-1";
	} cout << endl;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int t; cin >> t;
	while (t--)code3();
}