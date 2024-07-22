class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {

        int maxval = neededTime[0];
        int n = colors.length();
        int ans = 0;
        int f = 1; int sum = neededTime[0];
        for (int i = 1; i < n; i++) {
            if (colors[i] == colors[i - 1]) {
                sum += neededTime[i];
                if (maxval < neededTime[i])maxval = neededTime[i];
                f = 0;
            } else {
                if (!f) {ans += sum - maxval; f = 1;}
                maxval = neededTime[i]; sum = neededTime[i];
            }
        }
        if (!f) {ans += sum - maxval;}
        return ans;
    }
};