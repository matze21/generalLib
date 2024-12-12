#include <vector>

using namespace std;

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        k = k % n;
        int s = n-1;
        int i = s - k+1;
        if (i>0) {
        reverse(nums, i,s);

        i = 0;
        s = n-1;
        reverse(nums, i,s);

        s = n-1;
        reverse(nums,k,s);
        }
    }
    void reverse(vector<int>& nums, int i, int s){
        while((s-i) >=1){
            int placeholder = nums[i];
            nums[i] = nums[s];
            nums[s] = placeholder;
            i++;
            s--;
        }
    }

    void rotate2(vector<int>& nums, int k){
        int n = nums.size();
        vector<int> temp(n);
        
        for(int i = 0; i<nums.size(); i++){
            temp[(i+k)%n] = nums[i];
        }
        nums=temp;
    }
};