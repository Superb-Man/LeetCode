class Solution {
public:

    int mostOccur(std::vector<int>&nums,int most) {
        int cnt = 0;
        for (int i = 0; i< nums.size(); i++) {
            if (nums[i] == most) cnt++;
            if (cnt >= (nums.size()+1)/2) return most;
        }
        return -1;

    }

    int majorityElement(vector<int>& nums) {
        // can be done with map for sure!
        // but linear time
        // O(1) space extra
        // counter array wont work because nums(i) <= 1e9
        // more than floor(n/2) times occurance
        // Pegionhole priciple.
        // at least two of them be together
        // check 1st two
        // check last two
        // check middle two

        int fast = 0;
        int last = nums.size()-1;
        int most; 

        most = mostOccur(nums,nums[fast]);
        if (most != -1) return most;
        most = mostOccur(nums,nums[last]);
        if (most != -1) return most;

        most = mostOccur(nums,nums[fast+1]);
        if (most != -1) return most;
        most = mostOccur(nums,nums[last-1]);
        if (most != -1) return most;

        most = mostOccur(nums,nums[(nums.size()+1)/2]);
        if (most != -1) return most;

        return -1;

    }
};
        