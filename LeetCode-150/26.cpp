class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        // sjoja yahoo!
        int cnt = 0;
        for (int i = 0 ; i < nums.size() -1 ; i++) {
            if (nums[i] != nums[i+1]) {
                nums[cnt++] = nums[i];
            }
        }
        nums[cnt++] = nums[nums.size()-1];

        return cnt;
    }
};