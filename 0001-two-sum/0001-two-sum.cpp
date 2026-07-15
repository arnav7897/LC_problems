class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        unordered_map<int,int> m;
        vector<int> ans(2);
        for(int i=0 ;i<n;i++){
            if(m.find(target-nums[i])!=m.end() && m[target-nums[i]] != i){
                ans[0] = i;
                ans[1] = m[target-nums[i]]; 
                break;
            }
            m[nums[i]] = i;
        }
        return ans;
    }
};