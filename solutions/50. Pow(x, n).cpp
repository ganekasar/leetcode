class Solution {
public:
    double myPow(double x, int n) {
        
        double answer = 1;
        int p = abs(n);
        
        if(n < 0)
            x = 1 / x;
        
        while(p) {
            if(p & 1)
                answer *= x;
            x = (x * x);
            p /= 2;
        }
        
        return answer;
    }
};
