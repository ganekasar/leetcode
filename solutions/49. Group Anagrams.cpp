class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<string,vector<string>> groups;
        
        for(string str : strs) {
            string key = str;
            sort(key.begin(), key.end());
            
            groups[key].push_back(str);
        }
        
        vector<vector<string>> answer;
        
        for(auto it : groups)
            answer.push_back(it.second);
        
        return answer;
    }
};
