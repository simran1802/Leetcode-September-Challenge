class Solution {
public:
    string largestNumber(vector<int>& nums) {
        vector<string> helper;
        for(auto i:nums){
            helper.push_back(to_string(i));
        }
        sort(helper.begin(),helper.end(),[](string &s1,string &s2){
            return s1+s2 > s2+s1;});
        string res;
        for(auto s : helper)
            res += s;
        while(res[0]=='0' && res.size()>1)
            res.erase(0,1);
        return res;
    }
};
