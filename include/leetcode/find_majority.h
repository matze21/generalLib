#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int,int> frequency;
        int n = nums.size();

        for (int& i :nums)
        {
            frequency[i]+=1;
            if(frequency[i] > n/2)
            {
                return i;
            }
        }
        return 0;
    }
    // boyer -moore voting algo
    int majorityElement1(vector<int>& nums) {
        int candidate = 0;
        int count = 0;
        for (int& i : nums) {
            if (count == 0) {
                candidate = i;
            }
            if (candidate == i){
                count++;
            }
            else {
                count--;
            }
        }
        return candidate;
    }
};