typedef long long ll;

int code(ll n) {
	ll temp =   (n * (n - 1)) / 2;
// 	cout<<"temp inside code:"<<temp<<endl;
	return temp;
}
long long int calculate(int ar[], int n)
{
	// Complete the function
	unordered_map<ll, ll> mp;
	for (int i = 0; i < n; i++) {
		mp[ar[i]] += 1;
	}
	ll ans = 0;
	for (auto it : mp) {
		if (it.second > 1) {
			ans += code(it.second);
		}
	} return ans;
}