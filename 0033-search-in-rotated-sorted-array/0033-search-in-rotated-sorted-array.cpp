class Solution {
public:
    int bs(int s , int e , vector<int>& a , int t){
        while(s <= e){
            int mid = s + (e-s)/2;
            if(a[mid] == t){
                return mid;
            }else if(a[mid] < t){
                s = mid +1 ;
            }else{
                e = mid -1;
            }
        }
        return -1;
    }
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        if(nums[0] < nums[n-1]){
            return bs(0 , n-1, nums, target);
        }

        int s = 0;
        int e = n-1;
        while(e > s){
            int mid = s + (e - s)/2;
            if(nums[mid] >= nums[0]){
                s = mid +1 ;
            }else{
                e = mid;
            }
        }
        int pivot = s;
        if(target == nums[pivot]){
            return pivot;
        }else if(target >= nums[0]){
            return bs(0 , pivot -1 , nums , target);
        }else{
            return bs(pivot , n-1 , nums , target);
        }
    }
};