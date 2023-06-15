class Solution {
public:
	void dfs (vector <vector <int>> &vis, vector <vector <int>> &heights, int i, int j, int prev) {
		int n = heights.size();
		int m = heights[0].size();
		if (i < 0 || j < 0 || i >= n || j >= m) return;
		if (heights[i][j] < prev || vis[i][j]) return;
		vis[i][j] = 1;
		int temp = heights[i][j];
		// heights[i][j] = -1;
		dfs (vis, heights, i + 1, j, temp);
		dfs (vis, heights, i - 1, j, temp);
		dfs (vis, heights, i, j - 1, temp);
		dfs (vis, heights, i, j + 1, temp);
		// heights[i][j] = temp;
	}
	vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
		int n = heights.size();
		int m = heights[0].size();
		vector <vector <int>> vis1(n, vector <int> (m));
		vector <vector <int>> vis2(n, vector <int> (m));
		for (int i = 0; i < n; i++) {
			dfs (vis1, heights, i, 0, -1);
			dfs (vis2, heights, i, m - 1, -1);
		}
		for (int i = 0; i < m; i++) {
			dfs (vis1, heights, 0, i, -1);
			dfs (vis2, heights, n - 1, i, -1);
		}
		vector <vector <int>> ans;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (vis1[i][j] && vis2[i][j]) {
					ans.push_back({i, j});
				}
			}
		}
		return ans;
	}
};