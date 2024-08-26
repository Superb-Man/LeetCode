class Solution {
public:
    int jump(vector<int>& nums) {
        int mx = 0;
        int omx = 0;
        int jump = 0;
        for (int i = 0; i < nums.size()-1; i++) {
            mx = max(mx,nums[i]+i);

            if (omx == i) {
                jump++;
                omx = mx;
            }
        }

        return jump;
    }
};