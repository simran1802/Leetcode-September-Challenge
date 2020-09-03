class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        int n = s.length();
        for(int i=1;i<=n/2;i++)
            if(n%i == 0 && s.substr(i) == s.substr(0,n-i))
                return true;
    
        return false;
    }
};
