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
	int temp = n;
	// checking if 101 is present as a subsequence
	int f = 0; int last_ind_0 ;
	int ind = 0;
	// check if 1 is present
	while (temp) {
		if (temp & 1) { f = 1; ind += 1; temp = temp >> 1; break;}
		else temp = temp >> 1;
		ind += 1;
	}
	if (!f) {cout << "0" << endl; return;}
	//check if 0 is present
	f = 0;
	while (temp) {
		if ( !(temp & 1)) { f = 1;  last_ind_0 = ind; temp = temp >> 1; ind += 1; break;} else temp = temp >> 1;
		ind += 1;
	}
	if (!f) {cout << "0" << endl; return;}
	f = 0;
	// check 1 is present
	while (temp) {
		if (temp & 1) {f = 1; break;} else {temp = temp >> 1; last_ind_0 = ind; }
		ind += 1;
	}
	if (!f) {cout << "0" << endl; return;}
	// now go till msb to find last occurence of 0
	while (temp) {
		if ( !(temp & 1))last_ind_0 = ind;
		ind += 1;
		temp = temp >> 1;
	}
	// now iterate till last index where 0 isfound
	temp = n;
	ind = 0;
	int cost = 0;
	while (ind != last_ind_0) {
		if (temp & 1) {
			int aux = (1 << ind);
			temp = temp + 1; cost += aux;
		}
		temp = temp >> 1;
		ind += 1;
	}
	cout << cost << endl;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int t; cin >> t;
	while (t--)
		code();
}