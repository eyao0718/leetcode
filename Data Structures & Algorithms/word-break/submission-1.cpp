class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        // define dp[i] = true if s[i:] can be segmented
        vector<bool> dp(s.length() + 1, false);
        dp[s.length()] = true;
        for (int i = s.length() - 1; i >= 0; i--) {
            for (string& word : wordDict) {
                if (i+word.length()-1 < s.length() && s.substr(i, word.length()) == word) {
                    dp[i] = dp[i + word.length()];
                    if (dp[i]) {
                        break;
                    }
                }
                
            }
        }
        return dp[0];
    }
};