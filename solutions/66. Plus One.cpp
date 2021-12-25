class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int i = digits.size() - 1;
    
        while(i >= 0) {
            if(digits[i] == 9) {
                digits[i] = 0;
                i--;
            } else {
                digits[i]++;
                break;
            }        
        }
        
        if(i == -1) {
            reverse(digits.begin(), digits.end());
            digits.push_back(1);
            reverse(digits.begin(), digits.end());
        }
        
        return digits;
    }
};
