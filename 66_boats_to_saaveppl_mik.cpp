class Solution {
public:
    int numRescueBoats(vector<int>& ar, int limit) {
        int n = ar.size();
        int l = 0, r = n - 1; sort(ar.begin(), ar.end()); int cnt = 0;
        while (l <= r) {
            if (l == r) {cnt += 1; break;}
            int sum = (ar[l] + ar[r]);
            if ( sum <= limit) {l += 1; r -= 1;}
            else if ( sum > limit) {r -= 1; }

            cnt += 1;
        } return cnt;
    }
};