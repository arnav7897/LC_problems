class Solution {
public:
    int reverseDegree(string s) {
        int res = 0;
        int i = 1;
        for(char ch : s){
            res += i*('z' - ch + 1);
            i++;
        }
        return res;
    }
};