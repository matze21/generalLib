#include <vector>

using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        vector<int> result;
        for(auto& i : nums)
        {
            if(result.empty() || result.back() != i)
            {
                result.push_back(i);
            }
        }
        nums=result;
        return nums.size();
    }
    int removeDuplicates2(vector<int>& nums) {
        if (nums.size()<=2)
        {
            return nums.size();
        }
        int k = 2;
        int i = 2;
        int len = nums.size();
        while(i<len)
        {
            if(nums[i] == nums[k-2])
            {
                i++;
            }
            else
            {
                nums[k] = nums[i];
                k++;
                i++;
            }
        }
        return k;
    }
};