class Solution {
public:
    int reverse(int x) {
        if (x == -2147483648)
            return 0;
        
        int sign = x < 0 ? -1 : 1;
        int ans = 0;
        if (x < 0) {
            x *= -1;
        }
        
        
        while(x) {
            if (ans > 214748364)
                return 0;
            if (ans == 214748364 && (x%10) > 7)
                return 0;
            ans = ans * 10 + (x % 10);
            x /= 10;
        }
        
        ans *= sign; 
        return ans;
    }
};
