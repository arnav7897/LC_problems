class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        priority_queue<pair<int,int>> pq;
        unordered_map<int,int> m;
        for(auto &it : nums){
            m[it]++;
        }
        for(auto[a,b]:m){
            pq.push({b,a});
        }
        vector<int> ans;
        while(!pq.empty() && k>0){
            auto [a,b] = pq.top();
            ans.push_back(b);
            pq.pop();
            k--;
        }
        return ans;
    }
};