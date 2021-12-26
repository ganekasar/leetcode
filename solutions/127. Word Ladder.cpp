class Solution {
public:
    int ladderLength(string start, string target, vector<string>& dict) {
        sort(dict.begin(), dict.end());
    
        if(!binary_search(dict.begin(), dict.end(), target))
            return 0;
​
        int level = 1, wordLength = start.size();
​
        queue<string> q;
        map<string,bool> visited;
        q.push(start);
        visited[start] = true;
​
        while(!q.empty()) {
            level++;
​
            int qsize = q.size();
​
            while(qsize--) {
                string word = q.front();
                q.pop();
​
                for(int pos = 0; pos < wordLength; pos++) {
                    char orig_char = word[pos];
​
                    for(char ch = 'a'; ch <= 'z'; ch++) {
                        word[pos] = ch;
​
                        if(word == target)
                            return level;
                        
                        if(visited[word])
                            continue;
​
                        if(!binary_search(dict.begin(), dict.end(), word))
                            continue;
​
                        q.push(word);
                        visited[word] = true;
                    }
​
                    word[pos] = orig_char;
                }
            }
        }
​
        return 0;
    }
};
