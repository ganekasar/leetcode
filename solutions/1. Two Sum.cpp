class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int,int> positions;
        
        for(int i = 0; i < (int)nums.size(); i++) {
            int complement = target - nums[i];
            
            if(positions.find(complement) != positions.end())
                return {positions[complement], i};
            
            positions[nums[i]] = i;
        }
        
        return {};
    }
};
​
/*
    Time Complexity  - O(n)
    Space Complexity - O(n)
​
*/
