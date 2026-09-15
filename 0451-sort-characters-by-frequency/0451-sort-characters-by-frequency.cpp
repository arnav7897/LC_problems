class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char , int> m;
        for(auto ch: s){
            m[ch]++;
        }   

        priority_queue<pair<int,int>> pq;

        for(auto &[a,b]: m){
            pq.push({b,'z'-a});
        }
        string ans = "";
        while(!pq.empty()){
           int a = pq.top().first;
           char b = 'z' - pq.top().second;
           for(int i = 0;i<a;i++){
                ans+=b;
           }
           pq.pop();
        }
        return ans;
    }
};