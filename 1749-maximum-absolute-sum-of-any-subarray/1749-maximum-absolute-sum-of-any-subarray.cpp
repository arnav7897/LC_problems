class Solution {
public:
    int maxAbsoluteSum(vector<int>& a) {
        int n = a.size();
        int curr = a[0];
        int best = a[0];
        int mincurr = a[0];
        int bestmin = a[0];

        for(int i = 1 ;i < n;i++){
            int prev = curr;
            int prevmin = mincurr;
            curr = max(prev + a[i] , a[i]);
            mincurr = min(prevmin + a[i] , a[i]);

            best = max(best , curr);
            bestmin = min(bestmin , mincurr);
        }
        return max(abs(best), abs(bestmin));
    }
};