class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0)
            return false;
        long long reverse = 0;
        int val = x;
        while (x) {
            reverse = reverse * 10 + (x % 10);
            x /= 10;
        }
        return reverse == val;
    }
};
