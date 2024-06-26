class Solution {
public:
    int maxSubArray(vector<int>& ar) {
        int n = ar.size();
        int ans = INT_MIN;
        int sum = 0;
        for (int i = 0; i < n; i++) {
            sum += ar[i];
            if (sum > ans)ans = sum;
            if (sum < 0)sum = 0;
        } return ans;
    }
};