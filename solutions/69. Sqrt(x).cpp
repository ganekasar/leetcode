class Solution {
public:
    int mySqrt(int x) {
        int low = 1, high = x;
        int squareRoot = 0;
        
        while(low <= high) {
            int mid = low + (high - low) / 2;
            
            if(1LL*mid*mid <= 1LL*x) {
                squareRoot = mid;
                low = mid + 1;
            } else 
                high = mid - 1;
        }
        
        return squareRoot;
    }
};
