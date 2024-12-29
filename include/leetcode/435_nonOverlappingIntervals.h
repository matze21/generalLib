#include <vector>
using namespace std;

class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        if(intervals.size()<2){return 0;}
        sort(intervals.begin(),intervals.end(), [](vector<int>& a, vector<int>& b){return a[1]<b[1];});
        int numRemoved = 0;
        int lastEnd = intervals[0][1];
        for(int i=1;i<intervals.size();i++){
            if(intervals[i][0]<lastEnd){
                numRemoved++;
            } else {
                lastEnd = intervals[i][1];
            }
        }
        return numRemoved;
    }
};