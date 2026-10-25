class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> ans;
        unordered_map<string , vector<string>> mp;
        int n = strs.size();
        for(int i = 0; i< n; i++){
            string temp(strs[i].begin() , strs[i].end());
            sort(temp.begin() , temp.end());
            mp[temp].push_back(strs[i]);
        }
        for(auto&[a, it] : mp){
            ans.push_back(it);
        }
        return ans;
    }
};