class Solution {
    bool check(string& s, string& p, int s_ind, int p_ind) {
        if (s_ind == 0 && p_ind == 0)
            return true;
        if (p_ind == 0)
            return false;
        if (s_ind == 0) {
            if (p[p_ind - 1] == '*')
                return check(s, p, s_ind, p_ind - 2);
            else
                return false;
        }
        
        if (s[s_ind - 1] == p[p_ind - 1] || p[p_ind - 1] == '.')
            return check(s, p, s_ind - 1, p_ind - 1);
        if (p[p_ind - 1] == '*') {
            int cur = s_ind - 1;
            bool ok = check(s, p, s_ind, p_ind - 2);
            while (cur >= 0 && (s[cur] == p[p_ind - 2] || p[p_ind - 2] == '.')) {
                ok |= check(s, p, cur, p_ind - 2);
                cur--;
            }
            return ok;
        }
        return false;
    }
public:
    bool isMatch(string s, string p) {
        return check(s, p, s.size(), p.size());
    }
};
