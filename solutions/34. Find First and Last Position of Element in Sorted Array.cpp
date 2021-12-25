class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int first = nums.size(), last = -1, low = 0, high = nums.size() - 1;
        
        while(low <= high) {
            int mid = low + (high - low)/2;
            
            if(nums[mid] > target) {
                high = mid - 1;
            } else if(nums[mid] < target) {
                low = mid + 1;
            } else {
                first = mid;
                high = mid - 1;
            }
        }
        
        low = 0, high = nums.size() - 1;
        
        while(low <= high) {
            int mid = low + (high - low)/2;
            
            if(nums[mid] > target) {
                high = mid - 1;
            } else if(nums[mid] < target) {
                low = mid + 1;
            } else {
                last = mid;
                low = mid + 1;
            }
        }
        
        if(last == -1)
            return {-1, -1};
        else
            return {first, last};
    }
};
