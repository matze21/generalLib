#include <vector>

using namespace std;
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int min = 1e6;
        int max = 0;
        int prof = 0;
        for (int& i : prices)
        {
            if (i<min){
                min=i;
                max=i;
            }
            if(i>max){
                max=i;
            }
            int p = max-min;
            if (p > prof){
                prof=p;
            }
        }
        
        if (prof < 0){
            prof = 0;
        }
        return prof;
    }
};

class SolutionCummulatedProfit {
public:
    int maxProfit(vector<int>& prices) {
        int prof = 0;
        for(int i =1; i<prices.size(); i++){
            int diff = prices[i]-prices[i-1];
            if (diff>0){
                prof += diff;
            }
        }
        return prof;
    }
};