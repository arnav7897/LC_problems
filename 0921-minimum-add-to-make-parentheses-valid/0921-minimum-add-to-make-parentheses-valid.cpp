class Solution {
public:
    int minAddToMakeValid(string s) {
        int balance = 0;
        int ans = 0;
        for(auto c : s){
            if(c == ')'){
                balance--;
            }else{
                balance++;
            }
            if(balance < 0){
                ans += abs(balance);
                balance=0;
            }
        }   
        if(balance != 0){
            ans += abs(balance);
        }
        return ans;
    }
};