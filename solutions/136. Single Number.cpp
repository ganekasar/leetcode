class Solution {
public:
    int singleNumber(vector<int>& nums) {
        if(nums.size() == 0)
            return 0;
        
        int answer = 0;
        
        for(int x : nums)
            answer ^= x;
        
        return answer;
    }
};
