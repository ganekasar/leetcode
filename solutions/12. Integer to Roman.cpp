class Solution {
public:
    string intToRoman(int num) {
        
        map<int, string> m;
        
        m[1] = "I";
        m[4] = "IV";
        m[5] = "V";
        m[9] = "IX";
        m[10] = "X";
        m[40] = "XL";
        m[50] = "L";
        m[90] = "XC";
        m[100] = "C";
        m[400] = "CD";
        m[500] = "D";
        m[900] = "CM";
        m[1000] = "M";
        
        string answer;
        
        int mul = 1000;
            
        while(num > 0 && mul > 0) {
            while(num >= mul) {
                answer.append(m[mul]);
                num -= mul;
            }
​
            if(num >= 9*mul/10) {
                answer.append(m[9*mul/10]);
                num -= 9*mul/10;
            } else if(num >= 5*mul/10) {
                answer.append(m[5*mul/10]);
                num -= 5*mul/10;
            } else if(num >= 4*mul/10) {
                answer.append(m[4*mul/10]);
                num -= 4*mul/10;
            } 
​
            while(num >= mul/10) {
                answer.append(m[mul/10]);
                num -= mul/10;
            }
            
            mul /= 10;
        }
        
        return answer;
    }
};
