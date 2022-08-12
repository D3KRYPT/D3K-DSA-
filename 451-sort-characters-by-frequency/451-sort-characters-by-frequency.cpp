class Solution {
public:
    string frequencySort(string s) {
        vector < pair < int, char > > hash(123, {0,0});
        
        for (auto c : s)
            hash[c] = {hash[c].first + 1, c};
        
        string res = "";
        
        sort(hash.begin(), hash.end());
        
        for(auto p : hash)
        {
            res = string(p.first, p.second) + res;
        }
        
        return res;
    }
};