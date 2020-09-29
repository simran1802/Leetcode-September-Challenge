class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int ll = s.size();
        unordered_set<string> seen;
        for(const auto& s : wordDict) {
            seen.insert(s);
        }
        vector<int> dp(ll+1);
        dp[0] = true;
        for(int i = 0; i <= ll ; i++){
            for(int j = 0; j < wordDict.size(); j++){
                if(dp[i]){
                    string str = s.substr(i,wordDict[j].size());
                    if(seen.count(str)){
                        dp[i+str.size()] = true;
                    }
                }
            }
        }
        return dp[ll];
    }
};
