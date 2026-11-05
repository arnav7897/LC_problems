class Solution {
public:
    int findTheDistanceValue(vector<int>& arr1, vector<int>& arr2, int d) {
        // taking an element arr1 iterating the arr2 to find the element which is in between 
        // arr[i]+d >= arr2[j] >=arr[i]-d; O(n * m)
        int n = arr1.size() , m = arr2.size();
        int ans = 0;
        for(int i =0 ;i<n ;i++){
            bool flag = false;
            for(int j = 0;j<m ;j++){   
                if(arr2[j] <= arr1[i]+d && arr2[j] >=arr1[i]-d){
                    flag=true;
                    break;
                } 
            }
            if(!flag){
                ans++;
            }
        }   
        return ans;
    }
};