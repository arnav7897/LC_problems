class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int ans = 0;
        vector<int> a; 
        int n = nums.size();
        for(int i = 0; i<n ;i++){
            if(nums[i] != val){
                ans++;
                a.push_back(nums[i]);
            }
        }
        for(int i = 0 ; i<a.size() ;i++){
            nums[i] = a[i];
        }   
        return ans;
    }
};