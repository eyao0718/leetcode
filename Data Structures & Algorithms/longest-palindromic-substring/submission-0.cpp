class Solution {
public:
    string longestPalindrome(string s) {
        int index = 0;
        int len = 1;
        int N = s.length();
        if (N <= 1) {
            return s;
        }
        std::vector<std::vector<bool>> dp(N, std::vector<bool>(N, true));
        for (int i = 0; i < N; i++) {
            dp[i][i] = true;
        }
        for (int l = 2; l <= N; l++) {
            for (int i = 0; i <= N - l; i++) {
                int end = i + l - 1;
                if (s.at(i) == s.at(end)) {
                    if (i + 1 > end - 1) {
                        dp[i][end] = true;
                    } else {
                        dp[i][end] = dp[i + 1][end - 1];
                    }
                } else {
                    dp[i][end] = false;
                }

                if (dp[i][end] && l > len) {
                    index = i;
                    len = l;
                }
            }
        }
        return s.substr(index, len);
    }
};