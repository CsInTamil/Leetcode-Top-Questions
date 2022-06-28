class Solution {
public:
    string longestPalindrome(string s) {
        int dp[s.size()][s.size()];
        for (int i = 0 ; i < s.size(); i++)
            for (int j = 0 ; j < s.size() ; j++)
                dp[i][j] = -1;
        
        int longest = 1;
        int start = 0;
        int count = 1;
        for (int i = 1 ; i <= s.size() ; i++) {
            for (int j = 0 ; j + i - 1 < s.size(); j++) {
                if (i == 1)
                    dp[j][j] = 1;
                else if (i == 2 && s[j] == s[j + 1]) {
                    dp[j][j + 1] = 2;
                    longest = 2;
                    start = j;
                    count = 2;
                } else if (s[j] == s[j + i - 1] && dp[j + 1][j + i - 2] != -1) {
                    dp[j][j + i - 1] = dp[j + 1][j + i - 2] + 2;
                    if (dp[j][j + i - 1] > longest) {
                        longest = dp[j][j + i - 1];
                        start = j;
                        count = i;
                    }
                }
            }
        }
        return s.substr(start, count);
    }
};
