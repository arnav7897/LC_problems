class Solution {
public:
    int minStoneSum(vector<int>& p, int k) {
        priority_queue<int> pq;
        for(auto& it : p){
            pq.push(it);
        }
        for(int i = 0 ; i<k ;i++){
            if(pq.size() == 0){
                return 0;
            }
            int t = pq.top();
            // cout<<t<<endl;
            pq.pop();
            pq.push(t-t/2);
        }
        int ans = 0;
        while(!pq.empty()){
            ans += pq.top();
            pq.pop();
        }
        return ans;
    }
};