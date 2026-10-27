class Solution {
public:
    vector<string> createGrid(int m, int n) {
        vector<string> ans;
        for(int i =0 ;i<m; i++){
            string temp;
            if(i == 0){
                for(int j =0 ;j<n ;j++){
                    temp.push_back('.');
                }
            }else{
                for(int j = 0; j<n-1; j++){
                    temp.push_back('#');
                }
                temp.push_back('.');
            }
            ans.push_back(temp);
        }
        return ans;
    }
};