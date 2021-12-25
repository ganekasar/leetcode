class Solution {
public:
    string simplifyPath(string path) {
        vector<string> parent_dir;
        string curr_dir;
        
        path.push_back('/');
        
        for(auto ch : path) {
            if(ch == '/') {
                if(curr_dir.length() == 0)
                    continue;
                
                if(curr_dir == "..") {
                    if(parent_dir.size() > 0)
                        parent_dir.pop_back();
                } else if(curr_dir != ".")
                    parent_dir.push_back(curr_dir);
                
                curr_dir.clear();
            } else 
                curr_dir.push_back(ch);
        }
        
        if(parent_dir.size() == 0)
            return "/";
        
        string answer;
        
        for(auto dir : parent_dir) 
            answer.append("/" + dir);
        
        return answer;
    }
};
