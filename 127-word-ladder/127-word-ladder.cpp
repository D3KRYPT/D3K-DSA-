class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> s;
        bool flag = false;
        for(auto &word : wordList)
        {
            if(endWord.compare(word) == 0)
            {
                flag = true;
            }
            s.insert(word);
        }
        
        if(!flag) return false;
        
        queue<string> q;
        q.push(beginWord);
        int depth = 0;
        
        while(!q.empty())
        {
            depth++;
            int n = q.size(); //this gives me the total number of nodes that are present in the same level
            
            while(n != 0)
            {
                string cur = q.front();
                q.pop();
                
                for(int j = 0; j < cur.length(); j++)
                {
                    string temp  = cur;
                    for(char l = 'a'; l <= 'z'; l++)
                    {
                        temp[j] = l;
                        
                        if(temp.compare(cur) == 0)
                            continue;
                        if(endWord.compare(temp) == 0)
                            return (depth + 1);
                        if(s.find(temp) != s.end())
                        {
                            q.push(temp);
                            s.erase(temp);
                        }
                    }
                }
                n--;
            }
        }
        return 0;
    }
};