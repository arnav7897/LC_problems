class Solution {
public:
    int nthUglyNumber(int n) {
        vector<int> arr(n + 1);

        arr[1] = 1;

        int i2 = 1;
        int i3 = 1;
        int i5 = 1;

        for(int i = 2; i <= n; i++) {

            int x2 = 2 * arr[i2];
            int x3 = 3 * arr[i3];
            int x5 = 5 * arr[i5];

            arr[i] = min({x2, x3, x5});

            if(arr[i] == x2)
                i2++;

            if(arr[i] == x3)
                i3++;

            if(arr[i] == x5)
                i5++;
        }

        return arr[n];
    }
};