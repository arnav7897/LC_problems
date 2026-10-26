class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        vector<string> ans;
        unordered_map<string ,int> mp;
        int n = s.length();
        for(int i =0;i<n-9;i++){
            string temp(s.begin()+i , s.begin()+i+10);
            mp[temp]++;
        }
        for(auto&[key , value] : mp){
            if(value>1){
                ans.push_back(key);
            }
        }
        return ans;
    }
};