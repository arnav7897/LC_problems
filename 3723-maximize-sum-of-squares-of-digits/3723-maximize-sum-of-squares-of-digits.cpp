class Solution {
public:
    string maxSumOfSquares(int num, int sum) {
        if(9*num < sum){
            return "";
        }
        string s = "";
        for(int i = 0; i<num ;i++){
            for(int j = 9 ; j>=0 ;j--){
                if(sum >= j){
                    s.push_back('0'+j);
                    sum -= j;
                    break;
                }
            }
        }
        return s;
    }
};