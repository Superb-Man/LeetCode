
class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        //don't know if it will work
        int j = -1;
        int tot = 0;
        int curSum = 0;

        for (int i = 0; i < gas.size(); i++) {
            tot += gas[i] - cost[i];
            curSum += gas[i] - cost[i];

            if (curSum < 0) {
                j = i;
                curSum = 0;
            }
        }

        return (tot >= 0 ? j+1 : -1);
    }
};
