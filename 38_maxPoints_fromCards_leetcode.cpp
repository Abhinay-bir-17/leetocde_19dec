class Solution {
public:
    typedef long long ll;
    int maxScore(vector<int>& ar, int k) {
        int n = ar.size();
        int l = 0, r = (n - k) - 1;
        ll ans = INT_MAX, aux_sum = 0;
        for (int i = 0; i <= r; i++)aux_sum += ar[i];
        ll tot_sum = 0;
        for (int i = r + 1; i < n; i++)tot_sum += ar[i];
        tot_sum += aux_sum;
        ans = min(ans, aux_sum);
        while ((r + 1) < n) {
            aux_sum -= ar[l];
            r += 1;
            aux_sum += ar[r];
            l += 1;
            ans = min(ans, aux_sum);
        } return tot_sum - ans;
    }
};