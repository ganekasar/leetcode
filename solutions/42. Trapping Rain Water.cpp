class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size()
        int left = 0, right = n - 1;
        int answer = 0;
        int leftMax = 0, rightMax = 0;
        
        while(left <= right) {
            if(height[left] < height[right]) {
                if(leftMax > height[left])
                    answer += (leftMax - height[left]);
                leftMax = max(leftMax, height[left]);
                left++;
            } else {
                if(rightMax > height[right])
                    answer += (rightMax - height[right]);
                rightMax = max(rightMax, height[right]);
                right--;
            } 
        }
        
        return answer;
    }
};
