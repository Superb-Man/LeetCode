
class Solution {
public:
    int maxArea(vector<int>& height) {
        int i = 0,j = height.size()-1;
        int maxArea = 0;

        while(i < j) {
            maxArea = std::max(maxArea,(j-i)*std::min(height[i],height[j]));
            (height[i] < height[j]) ? i++ : j--;
        }

        return maxArea;
    }
};
