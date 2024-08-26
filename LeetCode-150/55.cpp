class Solution {
public:
    bool canJump(vector<int>& nums) {
        int mx = -1;
        for (int i = 0; i < nums.size(); i++) {
            //either take 1 step 
            // or take the max step
            mx = max(mx,nums[i]+i);
            if (mx >= nums.size()-1) return true;
            if (mx == i) return false;
        } 
        return true;
    }
};