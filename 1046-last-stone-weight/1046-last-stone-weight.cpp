class Solution {
public:
    int lastStoneWeight(vector<int>& s) {
        priority_queue<int> pq;
        for(auto& i:s){
            pq.push(i);
        }

        while(pq.size() > 1){
            int f = pq.top();
            pq.pop();
            int s = pq.top();
            pq.pop();
            int diff = f-s;
            if(diff>0){
                pq.push(diff);
            }
        }

        if(pq.empty()){
            return 0;
        }else{
            return pq.top();
        }

    }
};