class Solution {
public:
    string longestPalindrome(string X) {
        int n = X.size();
        string answer;
        
        if(n == 0)
            return answer;
        
        answer.push_back(X[0]);
        int maxLength = 1;
        
        for(int mid = 1; mid < n-1; mid++) {
            int len = 1;
            string str;
            str.push_back(X[mid]);
            
            for(int i = mid-1, j = mid+1; i >= 0 && j < n; i--, j++) {
                if(X[i] == X[j]) {
                    str.insert(str.begin(), X[i]);
                    str.push_back(X[j]);
                    len += 2;
                } else 
                    break;
            }
            
            if(len > maxLength) {
                maxLength = len;
                answer = str;
            }
        }    
        
        for(int mid = 0; mid < n-1; mid++) {
            if(X[mid] == X[mid+1]) {
                int len = 2;
                string str;
                str.push_back(X[mid]);
                str.push_back(X[mid+1]);
                
                for(int i = mid-1, j = mid+2; i >= 0 && j < n; i--, j++) {
                    if(X[i] == X[j]) {
                        str.insert(str.begin(), X[i]);
                        str.push_back(X[j]);
                        len += 2;
                    } else 
                        break;
                }
                
                if(len > maxLength) {
                    maxLength = len;
                    answer = str;
                }
            } 
        }
        
        return answer;
    }
};
