// https://leetcode.com/problems/maximum-xor-product/description/
//below is codewithmik soln
class Solution {
public:
	const int M = 1e9 + 7;
	typedef long long ll;
	int maximumXorProduct(long long a, long long b, int n) {
		ll xora = 0;
		ll xorb = 0;

		for (ll i = 49; i >= n; i--) {
			if ( a & (1ll << i))xora = xora ^ (1ll << i);
			if (b & (1ll << i))xorb = xorb ^ (1ll << i);
		}
		for (int i = n - 1; i >= 0; i--) {
			ll  sum1 = (a & (1ll << i)) ; ll sum2 = (b & (1ll << i));
			if (sum1 > 0)sum1 = 1; if (sum2 > 0)sum2 = 1;
			// cout << "sum1 is:" << sum1 << ",sum2:" << sum2 << endl;
			ll sum = sum1 + sum2;
			if (sum == 0 || sum == 2) {xora = xora ^ (1ll << i); xorb = xorb ^ (1ll << i);}
			else {
				if (xora > xorb)xorb = xorb ^ (1ll << i);
				else xora = xora ^ (1ll << i);
			}
		}

		xora = xora % M; xorb = xorb % M;
		// cout << "xora is:" << xora << ",xorb:" << xorb << endl;
		ll ans = (xora * xorb) % M; return ans;
	}
};
// my code using mik ideas