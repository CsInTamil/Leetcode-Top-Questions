class Solution {
public:
    int myAtoi(string s) {
        int ans = 0;
        int cur = 0;
        while (cur < s.size() && s[cur] == ' ') {
            cur++;
        }
        
        int sign = 1;
        if (s[cur] == '-') {
            sign = -1;
            cur++;
        } else if (s[cur] == '+') {
            cur++;
        }
        
        while (cur < s.size() && s[cur] >= '0' && s[cur] <= '9') {
            if (ans > 214748364) {
                if (sign == 1)
                    return 2147483647;
                else
                    return -2147483648;
            } else if (ans == 214748364) {
                if (sign == 1 && (s[cur] - '0') > 7)
                    return 2147483647;
                else if (sign == -1 && (s[cur] - '0') >= 8)
                    return -2147483648;
            }
            ans = ans * 10 + (s[cur] - '0');
            cur++;
        }
        ans *= sign;
        return ans;
    }
};
