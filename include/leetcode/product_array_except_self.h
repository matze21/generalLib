#include <vector>
using namespace std;

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        int s = n-1;
        vector<int>leftProduct(n,1);
        vector<int>rightProduct(n,1);
        for(int i=0; i<n; i++)
        {
            if(i==0){
                leftProduct[i] = nums[i];
                rightProduct[s] = nums[s];
            }
            else{
                leftProduct[i] = leftProduct[i-1]*nums[i];
                rightProduct[s] = rightProduct[s+1]*nums[n-i-1];
            }
            s--;
        }
        // can get rid of last loop and already put it into the second one
        vector<int> res(n,0);
        for(int i=0; i<n; i++)
        {
            if(i==0)
            {
                res[i] = rightProduct[i+1];
            }
            else if(i==n-1)
            {
                res[i] = leftProduct[i-1];
            }
            else
            {
                res[i]= leftProduct[i-1]*rightProduct[i+1];
            }
            
        }
        return res;
    }
};