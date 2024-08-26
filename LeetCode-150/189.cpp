class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        if (nums.size() == 0) return;
        int offset = k % nums.size();
        int count = 0;
        for (int start = 0; count < nums.size(); start++) {
            int current = start;
            int prev = nums[start];
            do {
                int next = (current + offset) % nums.size();
                int temp = nums[next];
                
                nums[next] = prev;
                prev = temp;
                current = next;
                count++;
            } while (start != current);
        }
    }
};
