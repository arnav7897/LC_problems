class Solution {
public:
    int lower(vector<int>& a, int t){
        int r = a.size() - 1; 
        int l = 0;
        int ans = -1;
        while(l<=r){
            int mid = l + (r-l)/2;
            if(a[mid] == t){
                ans = mid;
                r = mid -1;
            }else if(a[mid] > t){
                r = mid -1;
            }else{
                l = mid +1;
            }
        }
        return ans;
    }
    int upper(vector<int>& a, int t){
        int r = a.size() - 1; 
        int l = 0;
        int ans = -1;
        while(l<=r){
            int mid = l + (r-l)/2;
            if(a[mid] == t){
                ans = mid;
                l = mid +1;
            }else if(a[mid] > t){
                r = mid -1;
            }else{
                l = mid +1;
            }
        }
        return ans;
    }
    vector<int> searchRange(vector<int>& nums, int target) {
        int l = lower(nums,target);
        int u = upper(nums,target);

        return {l,u};
    }
};