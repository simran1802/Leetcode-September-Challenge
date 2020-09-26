class Solution {
public:
    int findPoisonedDuration(vector<int>& timeSeries, int duration) {
        int poison=0,start=0,end=0;
        for(auto time:timeSeries){
            if(time > end){
                poison += end-start;
                start = time;
            }
            end = time+duration;
        }
        return poison+end-start;
    }
};
