class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> f;
        for(auto&it : nums){
            f[it]++;
        }

        priority_queue<pair<int,int> , vector<pair<int,int>> , greater<pair<int,int>>> pq;

        for(auto &[a,b] : f){
            pq.push({b,a});
            if(pq.size()>k){
                pq.pop();
            }
        }
        vector<int> ans;
        while(!pq.empty()){
            ans.push_back(pq.top().second);
            pq.pop();
        }
        return ans;
    }
};