class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        // without bs
        int n = nums1.size();
        int m = nums2.size();
        vector<int> ans;
        int i = 0, j = 0;
        while (i < n && j < m) {
            if (nums1[i] > nums2[j]) {
                ans.push_back(nums2[j]);
                j++;
            } else {
                ans.push_back(nums1[i]);
                i++;
            }
        }

        while (i < n) {
            ans.push_back(nums1[i]);
            i++;
        }
        while (j < m) {
            ans.push_back(nums2[j]);
            j++;
        }
        if((n+m) % 2== 0){
            return (ans[(n+m)/2] + ans[(n+m)/2 -1])/2.0;
        }else{
            return ans[(n+m)/2];
        }
    }
};