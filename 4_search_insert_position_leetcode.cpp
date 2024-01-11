class Solution {
public:
    int searchInsert(vector<int>& ar, int k) {
        int l = 0;
        int n = ar.size();
        int r = n - 1;
        while (l <= r) {
            int m = (l + r) / 2;
            if (ar[m] == k)return m;
            else if ( ar[m] > k) {
                r = m - 1;
            } else {
                l = m + 1;
            }
        }
        if (r == -1)return 0;
        if (l == n)return n;
        return l;
    }
};