class Solution {
public:
	void code(int base_row, int base_col, int r, int c, int prev,
	          vector<vector<int>>&ar, int n) {

		int new_row = c; int new_col = n - r + 1;
		// cout << "here" << endl;
		if ( base_row == new_row && base_col == new_col) {
			ar[base_row - 1][base_col - 1] = prev; return;
		}
		int temp = ar[new_row - 1][new_col - 1];
		// cout << "new_row:" << new_row << ",new_col:" << new_col << endl;
		ar[new_row - 1][new_col - 1] = prev;
		code(base_row, base_col, new_row, new_col, temp, ar, n);
	}

	void rotate(vector<vector<int>>& matrix) {
		int n = matrix.size();
		int row = n;
		for (int l = 1, r = n; ; l += 1, r -= 1) {
			if (l >= r)break;
			for (int j = row; j > l; j--) {// j acts as a colm for me
				code(row, j, row, j, matrix[row - 1][j - 1], matrix, n);
			} row -= 1;
		}
	}
};