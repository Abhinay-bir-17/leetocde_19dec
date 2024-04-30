typedef long long ll;
vector<int> singleNumber (vector<int>&ar) {
	// Your code here plz abhinay bir
	int n = ar.size();
	ll xxory = 0;
	for (int i = 0; i < n; ++i)
	{
		/* code */
		xxory = xxory ^ ar[i];
	}
	int rsbm = xxory & (~xxory + 1);
	int a = 0, b = 0;
	for (int i = 0; i < n; ++i)
	{
		/* code */
		if (ar[i]&rsbm)a = a ^ ar[i];
		else b = b ^ ar[i];

	}
	vector<int> ans;
	ans.push_back(a); ans.push_back(b);
	return ans;

}


vector<int> FindExitPoint(int n, int m, vector<vector<int>>& ar) {
	// focus abhinay bir you can do it.


}