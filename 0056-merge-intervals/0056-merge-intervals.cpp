class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& in) {
        sort(in.begin() , in.end());
        int cs = in[0][0];
        int ce = in[0][1];
        vector<vector<int>> ans;
        int n = in.size();
        for(int i = 1; i<n ;i++){
            if(in[i][0] <= ce){
                ce = max(ce , in[i][1]);
            }else{
                ans.push_back({cs,ce});
                cs=in[i][0];
                ce=in[i][1];
            }
        }
        ans.push_back({cs,ce});
        return ans;
    }
};