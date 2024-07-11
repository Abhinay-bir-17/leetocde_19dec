class Solution {
public:
    int compress(vector<char>&ar) {
        int n =    ar.size();
        int cnt = 1;
        int l  = 0;
        for (int i = 1; i < n; i++) {
            if (ar[i] == ar[i - 1])cnt += 1;
            else {
                ar[l] = ar[i - 1]; l += 1;
                if (cnt > 1) {
                    string cnt_str = to_string(cnt);
                    for (char &ch : cnt_str) {
                        ar[l] = ch; l += 1;
                    } cnt = 1;
                }
            }
        }
        ar[l] = ar[n - 1]; l += 1;
        if (cnt > 1) {
            string cnt_str = to_string(cnt);
            for (char &ch : cnt_str) {
                ar[l] = ch; l += 1;
            }
        }
        return l;
    }
};