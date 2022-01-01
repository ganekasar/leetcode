class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int answer = 0;
        
        for(int bit = 0; bit < 32; bit++) {
            
            int count = 0;
            
            for(int j = 0; j < nums.size(); j++) {
                if((1 << bit)&nums[j])
                    count++;
            }
            
            if(count%3 != 0)
                answer |= (1 << bit);
        }
        
        return answer;
    }
};
