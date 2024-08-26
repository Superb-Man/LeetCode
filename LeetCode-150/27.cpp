class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        // two pointers ig ?

        int i = 0 , j = nums.size()-1;
        if (j == -1) return 0 ;
        if (j == 0) {
            return !(nums[0] == val);
        }

        while (i < j) {
            if (nums[i] == nums[j] && nums[i] == val) {
                j--;
            } else if (nums[i] == val) {
                std::swap(nums[i],nums[j]);
                j--;
                i++;
            } 
            else i++;
        }

        // for (int k = 0 ; k < nums.size() ; k++) {
        //     if (nums[k] == val) return k;
        // }
        // return nums.size();
        return (i == j && nums[i] == val) ? i : ((i > j) ? i : i+1); 
    }
};