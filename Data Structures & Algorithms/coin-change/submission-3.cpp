class Solution {
   public:
    int coinChange(vector<int>& coins, int amount) {
        int s = amount + 1;
        vector<int> dp(s, 0);
        dp[0] = 0;
        for (int i = 1; i < s; i++) {
            vector<int> temp;
            for (int j = 0; j < coins.size(); j++) {
                int rem = i - coins[j];
                if (rem >= 0 && dp[rem] >= 0) {
                    temp.push_back(dp[rem]);
                }
            }
            if (temp.size() == 0) {
                dp[i] = -1;
            } else {
                dp[i] = *min_element(temp.begin(), temp.end()) + 1;
            }
        }
        return dp[amount];
    }
};