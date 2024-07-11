//  tc is O(nlogn)
class Solution {
public:
    int code(vector<int>ar, int n, int ind) {
        int l = ind + 1;
        int r = n - 1;
        int ans;
        while (l <= r) {
            int mid = (l + r) / 2;
            if (ar[mid] > ar[ind]) {
                ans = mid; l = mid + 1;
            } else r = mid - 1;
        } return ans;
    }
    void nextPermutation(vector<int>& ar) {
        int n = ar.size();
        if (n == 1)return; int f = 0; int ind;
        for (int i = n - 2; i >= 0; i--) {
            if (ar[i] < ar[i + 1]) {
                f = 1;
                ind = code(ar, n, i);
                swap(ar[ind], ar[i]);  ind = i;
                break;
            }
        }
        if (!f) {
            sort(ar.begin(), ar.end()); return;
        }
        sort(ar.begin() + ind + 1, ar.end());
    }
};
//t.c is O(n) : instead of using sort, u can reverse the el from ind+1 to n-1 !!!

