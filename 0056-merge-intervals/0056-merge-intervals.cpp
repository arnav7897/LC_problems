class Solution {
public:
    static bool cmp(vector<int> &a , vector<int>&b){
        return a[0] < b[0];
    }
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin() , intervals.end() , cmp);

        int cend = intervals[0][1];
        int cstart = intervals[0][0];
        int n = intervals.size();
        vector<vector<int>> ans;
        for(int i = 1 ;i<n;i++){
            if(intervals[i][0] <= cend){
                cend = max(cend,intervals[i][1]);
            }else{
                ans.push_back({cstart , cend});
                cstart = intervals[i][0];
                cend = intervals[i][1];
            }
        }
        ans.push_back({cstart , cend});
    return ans;
    }
};