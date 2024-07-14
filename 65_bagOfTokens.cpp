class Solution {
public:
    int bagOfTokensScore(vector<int>& ar, int power) {
        int n = ar.size(); if (n == 0)return 0;
        sort(ar.begin(), ar.end());
        int score = 0;
        if (power >= ar[0]) {power -= ar[0]; score += 1;}
        else {return 0;}
        int l = 1, r = n - 1;
        int ans = 1;
        while (l <= r) {
            if (score == 0 && (power < ar[l]))break;

            if (score > 0) {
                if (power >= ar[l]) { score += 1; power -= ar[l]; l += 1;}
                else {
                    power += ar[r]; r -= 1; score -= 1;
                }
            } else {
                power -= ar[l]; l += 1; score += 1;
            }
            ans = max(ans, score);
        } return ans;
    }
};