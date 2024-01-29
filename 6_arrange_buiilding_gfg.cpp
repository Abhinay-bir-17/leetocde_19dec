//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
	const int M = 1e9 + 7;
	int TotalWays(int n)
	{
		// Code here
		if (n == 1)return 4;
		long long int a = 1, b = 1;// fuk man insanee ee
		for (int i = 2; i <= n; i++) {
			long long int temp = (a + b) % M;
			a = b; b = temp;
		}
		long long int temp = (a + b) % M * (a + b) % M  % M;
		return temp % M;
	}
};

//{ Driver Code Starts.
int main() {
	int tc;
	cin >> tc;
	while (tc--) {
		int N;
		cin >> N;
		Solution ob;
		int ans = ob.TotalWays(N);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends