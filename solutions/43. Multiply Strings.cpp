        string finalAnswer;
        
        for (int digit : answer) 
            finalAnswer.push_back(digit + '0');
        
        return finalAnswer;
    }
    
    vector<int> multiplyOneDigit(string& firstNumber, char& secondNumberDigit, int numZeros) {
        vector<int> currentResult(numZeros, 0);
        int carry = 0;
​
        for (char firstNumberDigit : firstNumber) {
            int multiplication = (secondNumberDigit - '0') * (firstNumberDigit - '0') + carry;
        
            carry = multiplication / 10;
            
            currentResult.push_back(multiplication % 10);
        }
​
        if (carry) 
            currentResult.push_back(carry);
        
        return currentResult;
    }
​
public:
    string multiply(string firstNumber, string secondNumber) {
        if (firstNumber == "0" || secondNumber == "0") 
            return "0";
        
        reverse(firstNumber.begin(), firstNumber.end());
        reverse(secondNumber.begin(), secondNumber.end());
        
        vector<vector<int>> results;
        
        for (int i = 0; i < secondNumber.length(); i++) 
            results.push_back(multiplyOneDigit(firstNumber, secondNumber[i], i));
        
        string answer = sumResults(results);
        
        reverse(answer.begin(), answer.end());
        
        return answer;
    }
};
