class Solution {
    int getAns(vector<int>& height) {
        int pre[height.size()];
        pre[0] = height[0];
        int ans = 0;
        for (int i = 1 ; i < height.size() ; i++) {
            int l = 0, r = i;
            while (l < r) {
                int mid = (l + r) / 2;
                if (pre[mid] >= height[i])
                    r = mid;
                else 
                    l = mid + 1;
            }
            
            ans = max(ans, height[i] * (i - l));
            pre[i] = max(pre[i - 1], height[i]); 
        }
        return ans;
    }
public:
    int maxArea(vector<int>& height) {
        int ans = getAns(height);
        reverse(height.begin(), height.end());
        return max(ans, getAns(height));
    }
};
