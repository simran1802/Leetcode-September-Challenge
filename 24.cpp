class Solution {
public:
    char findTheDifference(string s, string t) {
        int sum1=0,sum2=0;
        int n = s.size();
        for(int i=0;i<n;i++){
            sum1 += (int)s[i];
        }
        for(int i=0;i<n+1;i++){
            sum2 += (int)t[i];
        }
        return (char)(sum2-sum1);
    }
};
