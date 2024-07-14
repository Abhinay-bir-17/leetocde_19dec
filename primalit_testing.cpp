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
bool prime(int n) {

	for (int i = 2; i * i <= n; i++) {
		if ( n % i == 0)return false;
	}

	if (n <= 1)return false;
	return true;
}
/*logic for sieve is that every composite no i.e every non prime no has a prime
factor less than it, so for say n =17,it has not been marked as false by any prime
no below it hence its prime*/
void sieve(int n) {
	vector<bool> ar(n + 1, true);
	ar[0] = ar[1] = false; // 0 nd 1 r not primes
	for (int i = 2; i * i <= n; i++) { // start with i = 2
		/*instead of i<=n above we can write i*i<=n as ex: i=11 n =100
		then we wont have to go inside the below loop after n=11
		*/
		if (ar[i]) { // if i is a prime i.e it has not been marked as false by nos
			// b4 it
			// if( ((i%2)==0) && (i!=2))continue;
			/*note we dont need to write  the above as ar[i] if waala line
			takes care of it , insaaaane*/
			for (int j = i * i; j <= n; j += i)ar[j] = false;
			/*rather than doing j =2*i, we start from j =i*i as we
			have already marked no's j =2*i, j=3*i, j=4*i ... till
			j = (i-1)*i in previous iterations*/
		}
	}
}
void code() {
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int t; cin >> t;
	while (t--)
		code();
}
