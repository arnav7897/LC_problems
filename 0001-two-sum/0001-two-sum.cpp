class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> fq;
        int n = nums.size();
        for(int i =0 ;i<n ;i++){
            if(fq.find(target - nums[i]) != fq.end()){
                return {fq[target - nums[i]] , i};
            }
            fq[nums[i]] = i;
        }
        return {-1, -1};
    }
};