class Solution {
public:
    string reverseWords(string s) {
        int i = 0 ,j = 0;
        int n = s.length();
        while(i<n){
            while(i<n && s[i]==' '){
                i++;
            }
            while(i<n && s[i]!=' '){
                s[j] = s[i];
                j++;
                i++;
            }
            while(i<n && s[i] == ' '){
                i++;
            }
            if(i<n){
                s[j++] = ' ';
            }
        }
        s.resize(j);
        i = 0;
        reverse(s.begin() , s.end());
        n = s.length();
        int st = 0;
        while(i<n){
            
            while(i<n && s[i]==' '){
                i++;
            }
            st = i;
            while(i<n && s[i] != ' '){
                i++;
            }
            reverse(s.begin()+st , s.begin()+i);
        }
        return s;
    }
};