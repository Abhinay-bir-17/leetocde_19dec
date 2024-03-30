// recursion approach : 25/50 test cases
void code(vector<int>&ar, int n, int sum, int &ans, int ind, int aux_sum) {
	if (ind == n) {
		ans = min( ans,    abs(2 * aux_sum - sum));
		return;
	}
	code(ar, n, sum, ans, ind + 1, aux_sum + ar[ind]);
	code(ar, n, sum, ans, ind + 1, aux_sum);
}
int minSubsetSumDifference(vector<int>& ar, int n) {
	// Write your code here burrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrr
	int sum = 0;
	for (int i = 0; i < n; i++)sum += ar[i];
	int ans = sum;
	code(ar, n, sum, ans, 0, 0); return ans;
}

// rec + memorizatn : not possible
int minSubsetSumDifference(vector<int>& ar, int n) {
	// Write your code here.

}
// bottom up soln: just same as subset sum