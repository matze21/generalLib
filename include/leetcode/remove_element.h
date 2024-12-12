#include <vector>

using namespace std;

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        vector<int> result;
        for(vector<int>::iterator i = nums.begin(); i<nums.end();i++)
        {
            if (*i != val)
            {
                result.push_back(*i);
            }
        }
        nums=result;
        return result.size();
    }
};