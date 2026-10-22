class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();
        bool left = true;
        bool right = true;
        int idx = 0;
        for(int i = 0; i<n;i++){
            if(nums[i] == 0){
                idx = i;
                break;
            }
        }

        for(int i = 1; i<n-1; i++){
            int nx = (idx + i)%n;
            if(nums[nx] > nums[(nx+1)%n]){
                right = false;
                break;
            }
        }

        for(int i = 1 ; i<n-1 ;i++){
            int nx = ((idx - i)%n + n)%n;
            if(nums[nx] > nums[((nx -1)%n +n )%n]){
                left = false;
                break;
            }
        }
        if(left == false && right == false){
            return -1;
        }
        if(right){
            return min(idx , 2 + n - idx);
        }else{
            return min(idx + 2 , 1 + min(n-1-idx , 3+idx));
        }
    }
};