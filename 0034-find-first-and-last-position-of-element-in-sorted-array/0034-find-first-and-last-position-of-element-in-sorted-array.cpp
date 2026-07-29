class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int s = 0;
        int e = nums.size()-1;
        vector<int> ans;
        while(e>=s){
            int mid = s + (e-s)/2;
            if(nums[mid] == target){
                int temp = mid;
                while(temp<nums.size() && nums[temp] == target){
                    temp++;
                }
                ans.push_back(temp-1);
                temp = mid-1;
                while(temp >=0 && nums[temp] == target){
                    temp--;
                }
                ans.insert(ans.begin(),temp+1);
                return ans;
            }else if(nums[mid] > target){
                e = mid - 1;
            }else{
                s = mid + 1;
            }
        }
        return {-1 , -1};
    }
};