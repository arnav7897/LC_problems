class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        sort(pairs.begin() , pairs.end());
        int n = pairs.size();
        vector<int> t(n , 1);
        int maxi = 1;
        for(int i = 0;i<n;i++){
            for(int j = 0 ;j<i;j++){
                if(pairs[i][0] > pairs[j][1]){
                    t[i] = max(t[j]+1 , t[i]);
                    maxi = max(maxi , t[i]);
                }
            }
        }
        return maxi;
    }
};