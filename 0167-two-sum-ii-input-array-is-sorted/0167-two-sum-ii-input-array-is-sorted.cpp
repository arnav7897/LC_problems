class Solution {
public:
    vector<int> twoSum(vector<int>& num, int target) {
        int n = num.size();
        int r = n -1;
        int l = 0;   

        while(l < r){
            if(num[l] + num[r] == target){
                return {l+1 ,r+1};
            }else if(num[l] + num[r] > target){
                r--;
            }else{
                l++;
            }
        }
        return {-1,-1};
    }
};