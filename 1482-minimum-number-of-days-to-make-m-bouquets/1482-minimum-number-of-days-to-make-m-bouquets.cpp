class Solution {
public:
    bool help(int m , int l, int k , vector<int>& b){
        int c = 0;
        int n = b.size();
        int i =0;
        while(i<n){
            if(b[i] > m){
                i++;
                continue;
            }
            int s = i;
            int r = i;

            while(r < n && b[r]<=m){
                r++;
            }

            int len = r -s;
            l = l - (len/k);
            i = r;
        }
        return l <= 0;
    }
    int minDays(vector<int>& b, int l, int k) {
        long long p = 1ll*l*k;
        if(p > b.size()){
            return -1;
        }
        int s = 0;
        int e = INT_MIN;
        for(auto &a : b){
            e = max(e,a);
        }           
        while(e >= s){
            int m = s + (e-s)/2;
            if(help(m , l , k ,b)){
                e = m -1 ;
            }else{
                s = m+1;
            }
        }
        return s;
    }
};