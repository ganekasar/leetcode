class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        set<int> hashSet(nums.begin(), nums.end());
        int maxConsecutive = 0;
        
        for(int x : nums) {
            if(hashSet.find(x-1) == hashSet.end()) {
                int curr = x;
                
                while(hashSet.find(curr) != hashSet.end())
                    curr++;
                
                maxConsecutive = max(maxConsecutive, curr - x);
            }
        }
        
        return maxConsecutive;
    }
};
