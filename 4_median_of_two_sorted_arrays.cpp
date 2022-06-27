class Solution {
    double findNthValue(vector<int> nums1, vector<int> nums2, int n) {
        int len1 = nums1.size();
        int len2 = nums2.size();
        
        if (len1 > len2) {
            return findNthValue(nums2, nums1, n);
        }
        if (len1 == 0) {
            return nums2[n - 1];
        }
        if (n == 1) {
            return min(nums1[0], nums2[0]);
        }
        
        int half1 = min(len1, n / 2);
        int half2 = n - half1;
        
        if (nums1[half1 - 1] < nums2[half2 - 1]) {
            return findNthValue(vector<int>(nums1.begin() + half1, nums1.end()), nums2, n - half1);
        } else if (nums1[half1 - 1] > nums2[half2 - 1]) {
            return findNthValue(nums1, vector<int>(nums2.begin() + half2, nums2.end()), n - half2);
        }
        return nums1[half1 - 1];
    }
    
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int len1 = nums1.size();
        int len2 = nums2.size();
        
        if ((len1 + len2) % 2 == 0) {
            return (findNthValue(nums1, nums2, (len1 + len2) / 2) + findNthValue(nums1, nums2, (len1 + len2) / 2 + 1)) / 2;
        } 
        return findNthValue(nums1, nums2, (len1 + len2) / 2 + 1);
    }
};
