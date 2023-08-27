class Solution {
public:
	bool func (unordered_map <int, int> &mp, vector <int> &stones, int i, vector <vector <int>> &dp, int k) {
		int n = stones.size();
		if (i >= n - 1) return 1;
		if (dp[i][k] != -1) return dp[i][k];
		int curr_stone = stones[i];
		bool found = false;
		if (k != 1) {
			if (mp.find (curr_stone + k - 1) != mp.end ()) {
				found |= func (mp, stones, mp[curr_stone + k - 1], dp, k - 1);
			}
		}
		if (mp.find (curr_stone + k) != mp.end ()) {
			found |= func (mp, stones, mp[curr_stone + k], dp, k);
		}
		if (mp.find (curr_stone + k + 1) != mp.end () && i != 0) {
			found |= func (mp, stones, mp[curr_stone + k + 1], dp, k + 1);
		}
		return dp[i][k] = found;
	}
	bool canCross(vector<int>& stones) {
		int n = stones.size();
		unordered_map <int, int> mp;
		for (int i = 0; i < n; i++) {
			mp[stones[i]] = i;
		}
		vector <vector <int>> dp(n, vector <int> (2100, -1));
		return func (mp, stones, 0, dp, 1);
	}
};