class Solution {
public:
    int getMaxArea(vector<int> hist, int n) {
        stack<int> s;
        int answer = 0;
        int i = 0;
    
        while(i < n) {
            if(s.empty() or hist[s.top()] <= hist[i]) {
                s.push(i);
                i++;
            } else {
                int tp = s.top();
                s.pop();
            
                int area = hist[tp] * (s.empty() ? i : i - s.top() - 1);
            
                answer = max(answer, area);
            }
        }
    
        while(!s.empty()) {
            int tp = s.top();
            s.pop();
        
            int area = hist[tp] * (s.empty() ? i : i - s.top() - 1);
        
            answer = max(answer, area);
        } 
    
        return answer;
    }
​
    int maximalRectangle(vector<vector<char> > &A) {
        int n = A.size();
    
        if(n == 0)
            return 0;
    
        int m = A[0].size();
    
        if(m == 0)
            return 0;
    
        vector<int> mat[n];
