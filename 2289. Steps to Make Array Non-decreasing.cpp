class Solution {
public:
	int totalSteps(vector<int>& nums) {
		int n = nums.size();
		int ans = 0;
		stack <pair <int, int>> st;
		st.push({nums[n - 1], 0});
		for (int i = n - 2; i >= 0; i--) {
			int steps = 0;
			while (!st.empty() && nums[i] > st.top().first) {
				steps = max (steps + 1, st.top().second);
				st.pop();
			}
			st.push({nums[i], steps});
		}
		while (st.size() > 0) {
			ans = max (ans, st.top().second);
			st.pop();
		}
		return ans;
	}
};