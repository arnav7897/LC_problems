class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<long long , pair<int,int>> > pq;

        for(auto &it : points){
            long long dis = it[0]*it[0] + it[1]*it[1];
            pq.push({dis , {it[0] , it[1]}});    
            if(pq.size()>k){
                pq.pop();
            }
        } 

        vector<vector<int>> ans;
        while(!pq.empty()){
            auto [a,b] = pq.top();
            ans.push_back({b.first,b.second});
            pq.pop();
        }
                   

        return ans;
    }   
};