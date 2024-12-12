#include <vector>

using namespace std;
class Solution {
public:
    bool canJump(vector<int>& nums) {
        int maxIdx=0;
        for(int i = 0; i<nums.size();i++){
            int newMaxIdx = i+nums[i];
            if(maxIdx < i)
            {
                return false;
            }

            if(newMaxIdx > maxIdx)
            {
                maxIdx = newMaxIdx;
            }
        }
        return true;
    }
};