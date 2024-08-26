// O (n log n)
// class Solution {
// public:
//     int hIndex(vector<int>& citations) {
//         //easy approach
//         sort(citations.begin(), citations.end());

//         int ans = 0;
//         int mini = citations[citations.size()-1]+1;
//         for (int i = 0; i <citations.size(); i++) {
//             int n = citations.size();
//             mini = min(n-i,citations[i]);
//             ans = max(ans,mini);
//         }

//         return ans;
//     }
// };

class Solution {
public:
    int hIndex(vector<int>& citations) {
        //good approach
        // O(n) extra memory and O(n) time
        int n = citations.size();
        n = max(n,1005);
        int cnt[n+5];
        for (int i = 0; i < n+5 ; i++) cnt[i] = 0;

        for (int i = 0 ; i < citations.size(); i++) cnt[citations[i]]++;
        //cnt(i) = cnt(i) + cnt(i+1)
        // because if we have 3 papers with 3 citations then we have 3 papers with 2 citations

        for (int i = n+3 ; i >= 0; i--) {
            cnt[i] += cnt[i+1];
            if (cnt[i] >= i) return i ;
        }

        return -1;

    }
};