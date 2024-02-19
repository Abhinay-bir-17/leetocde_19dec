/*You are required to complete this function*/


class Solution {
public:
    int maxLen(vector<int>&ar, int n) {
        // Your code is here
        unordered_map<int, int> mp;
        int cumSum = 0, ans = INT_MIN;
        for (int i = 0; i < n; i++) {
            cumSum += ar[i];
            if (mp[cumSum]) {
                ans = max(ans, i + 1 - mp[cumSum]);
            } else mp[cumSum] = i + 1;
            if (!cumSum) { // cumsum is 0
                ans = max(ans, i + 1);
            }
        }
        if (ans == INT_MIN)return 0; return ans;
    }
};