class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        //sufix-prefix diye kora jabe
        // but O(n) extra memory
        // lets do it using O(1) extra memory
        // 32 bit integer result means we just have to calculate non-zero element contained subarray
        int mulf = 1;
        int f = -1;//first 0 
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i]) {
                mulf *= nums[i];
            }
            else {
                f++;
                if (f == 1) {
                    mulf = 0;
                    break;
                }
            }
        }
        for (int i = 0; i < nums.size(); i++) {
            if (!mulf) nums[i] = 0;
            else {
                if (f == -1) nums[i] = mulf/nums[i] ;
                else nums[i] = (nums[i] ? 0 : mulf);
            } 
        }

        return nums;
    }
};
