typedef vector<string> vs;
class Solution {
public:
    unordered_set<string> dict;    
    unordered_map<string, vs> dp;
    
    vector<string> solve(string str){
        int n = str.size();
        
        if(str == ""){            
            return {""};
        }
        
        if(dp.find(str) != dp.end())
            return dp[str];
        
        vector<string> ans;
        
        for(int i = 0; i < n; i++){
            string pref = str.substr(0, i + 1);                        
            
            if(dict.find(pref) != dict.end()){                
                vs temp = solve(str.substr(i + 1));                
                for(auto x: temp){                    
                    ans.push_back(pref + (x.size() > 0 ? " ": "") + x);
                }
                
            }
        }
            
        return dp[str] = ans;
    }
    
    vector<string> wordBreak(string str, vector<string>& wordDict) {
        
        for(auto x: wordDict)
            dict.insert(x);
        
        return solve(str);                        
    }
};
