class Solution {
public:
    bool wordPattern(string pattern, string str) {
        map<char,int> p;
        map<string,int> w;
        istringstream in(str);
        int i=0;
        int n = pattern.size();
        for(string word;in>>word;i++){
            if(i==n || p[pattern[i]] != w[word])
                return false;
            p[pattern[i]] = w[word] = i+1;
            
        }
        return i==n;
    }
};
