class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        stack<int> stk;
        int answer = 0;
        int i = 0;
        
        while(i < n) {
            if(stk.empty() or heights[stk.top()] <= heights[i]) {
                stk.push(i);
                i++;
            } else {
                int tp = stk.top();
                stk.pop();
                
                int area = heights[tp]*(stk.empty() ? i : i-stk.top()-1);
                
                answer = max(area, answer);
            }
        }
        
        while(!stk.empty()) {
            int tp = stk.top();
            stk.pop();
            
            int area = heights[tp]*(stk.empty() ? i : i-stk.top()-1);
            
            answer = max(area, answer);
        }
        
        return answer;
    }
};
