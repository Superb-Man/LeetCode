class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.size() < 3) return nums.size();
        //not sjoja yahoo!
        int i = 0, j = 2 ,cnt = 0 ;
        while (i < nums.size()-2 && j <= nums.size() -1) {
            if (nums[i] == nums[j]) {
                j++;
            }
            else {
                nums[cnt++] = nums[i];
                if (i == 0 || nums[i+1] != nums[cnt-2]) {

                    std::cout << "here\n";
                    nums[cnt++] = nums[i+1];
                }
                i = j; 
                j = i + 2;
            }
        }
        
        if ( j > nums.size()-1) j = nums.size()-1;
        if (i == j) nums[cnt++] = nums[j];
        else if (j-i == 1) {
            if (nums[i] != nums[j]) {
                nums[cnt++] = nums[i];
                nums[cnt++] = nums[j];
            }
            else {
                if (nums[i] == nums[cnt-1]) nums[cnt++] = nums[i];
                else {
                    nums[cnt++] = nums[i];
                    nums[cnt++] = nums[i];
                }
            }
        }
        else {
            i = nums.size() -1;
            if (cnt == 0 || nums[cnt-1] != nums[i]) {
                nums[cnt++] = nums[i];
                nums[cnt++] = nums[i];
            }
            else {
                nums[cnt++] = nums[i];
            }

        }

        return cnt;
    }
};