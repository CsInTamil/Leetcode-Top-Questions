class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        map<char,int> count;
        int start = 0;
        int end = 0;
        int ans = 0;
        while (end < s.size()) {
            count[s[end]]++;
            while (count[s[end]] > 1) {
                count[s[start]]--;
                start++;
            }
            ans = max(ans, end - start + 1);
            end++;
        }
        return ans;
    }
};
