class Solution {
public:
    bool isPalindrome(string s) {
        int l = 0;
        int n = s.length();
        int r = s.length()-1;
        while(l < r){
            while(l<n && !isalnum(s[l])){
                l++;
            }
            while(r>=0 && !isalnum(s[r])){
                r--;
            }
            if( l<n && r>=0 && r>l&& tolower(s[l])!=tolower(s[r])){
                return false;
            }
            l++;
            r--;
        }       
        return true; 
    }
};