#include<bits/stdc++.h>
typedef long long ll;
//Function to find two repeated elements.
ll fact(ll n) {
	ll ans = 1;
	for (ll i = 0; i < n; ++i)
	{
		/* code */ ans = ans * (i + 1);
	} return ans;
}
vector<int> twoRepeated (int ar[], int n) {
	// Your code here plz abhinay bir
	ll sum  = 0;
	ll prod = 1;
	for (ll i = 0; i < (n + 2); ++i)
	{
		/* code */
		sum += ar[i]; prod = prod * ar[i];
	} //cout<<"sum is:"<<sum<<"prod:"<<prod<<endl;
	ll xysum = sum - (n * (n + 1)) / 2;
	ll xyprod = prod / fact(n);
	// cout<<"xysum:"<<xysum<<",xyprod:"<<xyprod<<endl;
	ll xydif = sqrt( (xysum * xysum) - 4 * xyprod);

	ll x = (xydif + xysum) / 2;
	ll y = xysum - x;
	sum = 0;
	prod = 0;
	vector<int>ab;
	for (int i = 0; i < n + 2; i++) {
		if (ar[i] == x)sum += 1;
		else if (ar[i] == y)prod += 1;
		if (sum == 2) {
			ab.push_back(x); ab.push_back(y); break;
		} else if (prod == 2) {
			ab.push_back(y); ab.push_back(x); break;
		}
	}
	return ab;

}