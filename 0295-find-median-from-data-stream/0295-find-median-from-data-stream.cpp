class MedianFinder {
public:
    priority_queue<int , vector<int> , greater<int>> right; //min
    priority_queue<int> left; //max
    MedianFinder() {
        
    }
    
   void addNum(int num) {
        if (left.empty() || num <= left.top()) {
            left.push(num);
        } else {
            right.push(num);
        }

        if (left.size() > right.size() + 1) {
            right.push(left.top());
            left.pop();
        }
        else if (right.size() > left.size() + 1) {
            left.push(right.top());
            right.pop();
        }
    }

    
    double findMedian() {
        int m = right.size();
        int n = left.size();
        if((m+n)%2 == 0){
            int l = left.top();
            int r = right.top();
            double ans = (l+r)/2.0;
            return ans;
        }else{
            if(m>n){
                return right.top();
            }else{
                return left.top();
            }
        }
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */