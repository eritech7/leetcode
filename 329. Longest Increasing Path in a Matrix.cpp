class Solution {
public:
	int func (vector <vector <int>> &matrix, vector <vector <int>> &dp, int i, int j) {
		int n = matrix.size();
		int m = matrix[0].size();
		if (dp[i][j] != -1) return dp[i][j];
		vector <int> a = { -1, 1, 0, 0};
		vector <int> b = {0, 0, -1, 1};
		int pick = 0;
		for (int k = 0; k < 4; k++) {
			int row = a[k] + i;
			int col = b[k] + j;
			if (row >= 0 && col >= 0 && row < n && col < m && matrix[row][col] > matrix[i][j]) {
				pick = max (pick, 1 + func (matrix, dp, row, col));
			}
		}
		return dp[i][j] = pick;
	}
	int longestIncreasingPath(vector<vector<int>>& matrix) {
		int n = matrix.size();
		int m = matrix[0].size();
		vector <vector <int>> dp(n, vector <int> (m, -1));
		int ans = 1;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				ans = max (ans, 1 + func (matrix, dp, i, j));
			}
		}
		return ans;
	}
};