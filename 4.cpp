class Solution {
public:
    vector<int> partitionLabels(string S) {
        vector<int> char_idx(26,0);
        for(int i=0;i<S.size();i++)
            char_idx[S[i]-'a'] = i;
        
        vector<int> res;
        int max_idx = -1;
        int last_idx = 0;
        for(int i=0;i<S.size();i++){
            max_idx = max(max_idx, char_idx[S[i]-'a']);
            if(i == max_idx){
                res.push_back(max_idx-last_idx+1);
                last_idx = i+1;
            }
        
        }
        return res;

    }
};
