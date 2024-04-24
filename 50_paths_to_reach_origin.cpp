// recusrion
int code(int x, int y) {
	if (x == 0 && y == 0)return 1;
	if (x < 0 || y < 0)return 0;
	return code(x - 1, y) + code(x, y - 1);
}
int ways(int x, int y) {
	//code here abhinay bir focus

	return code(x, y);
}
// rec + memo
const int M = 1e9 + 7;
int code(int x, int y, vector<vector<int>>&dp) {
	if (x == 0 && y == 0)return 1;
	if (x < 0 || y < 0)return 0;
	if (dp[x][y] != -1)return dp[x][y];
	return dp[x][y] =  (code(x - 1, y, dp) + code(x, y - 1, dp)) % M;
}
int ways(int x, int y) {
	//code here abhinay bir focus
	vector<vector<int>>dp(x + 1, vector<int>(y + 1, -1));
	return code(x, y, dp);
}