class Solution {
public:
    string reorganizeString(string s) {
        int n = s.length();
        vector<int> f(26 , 0);
        for(char &ch : s){
            f[ch - 'a']++;
        }
        for(auto & it : f){
            if(it > (n+1)/2){
                return "";
            }
        }
        
        priority_queue<pair<int , char>> pq;
        for(int i =0;i<26;i++){
            if(f[i]!=0){
                pq.push({f[i],'a'+i});
            }
        }
        string ans = "";
        while(pq.size() >= 2){
            auto[a,b] = pq.top();
            pq.pop();
            auto[c,d] = pq.top();
            pq.pop();

            ans += b;
            ans += d;

            a--;
            c--;
            if(a>0){
            pq.push({a,b});
            }
            if(c>0){
                pq.push({c,d});
            }
            }
        
        if(pq.size() == 1){
            ans += pq.top().second;
        }
        return ans;
    }
};