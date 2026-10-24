class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int i = 2;
        
        int n = nums.size();
        if(n<=2){
            return n; 
        }
        for(int j = 2; j< n;j++){
            if(nums[i-2] != nums[j]){
                nums[i] = nums[j];
                i++;
            }
        }   
        return i;
    }
};