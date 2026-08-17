class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        intervals.push_back(newInterval);
        sort(intervals.begin() , intervals.end());
        
        int cend = intervals[0][1];
        int cstart = intervals[0][0];

        int n = intervals.size();

        vector<vector<int>> ans;

        for(int i =1 ;i<n; i++){
            if(cend >= intervals[i][0]){
                cend = max(cend , intervals[i][1]);
            }else{
                ans.push_back({cstart, cend});
                cstart = intervals[i][0];
                cend = intervals[i][1];
            }
        }

        ans.push_back({cstart , cend});
    return ans;
    }
};