
class Solution {
public:
    int trap(vector<int>& height) {
        int curMax = 0;
        int tot = 0;
        int last= 0;
        int totCur = 0;
        //protitar shamne highest maximum tower koto left to right
        for (int i = 0; i < height.size(); i++) {
            if (curMax <= height[i]) {
                curMax = height[i];
                last = curMax;
                tot+=totCur;
                totCur = 0;
            }
            totCur+=(curMax-height[i]);
        }

        curMax = 0;
        // ekhon sesh theke last porzonto ashbe
        for (int i = height.size()-1;height[i] != last; i--) {
            if (curMax <= height[i]) {
                curMax = height[i];
            }
            tot+=(curMax-height[i]);
        }

        return tot;
    }
};
