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


class Solution {
public:
    int compress(vector<char>& ar) {
        int n = ar.size();
        int ind = 0, cnt = 1;
        for (int i = 1; i < n; i++) {
            if (ar[i] == ar[i - 1]) {
                cnt += 1;
            } else {
                if (cnt > 1) {
                    ar[ind] = ar[i - 1]; ind += 1;
                    string temp = to_string(cnt);
                    for (int j = 0; j < temp.size(); j++) {
                        ar[ind] = temp[j]; ind += 1;
                    }
                    cnt = 1;
                } else { ar[ind] = ar[i - 1]; ind += 1;}
            }
        }
        if (cnt > 1) {
            ar[ind] = ar[n - 1]; ind += 1;
            string temp = to_string(cnt);
            for (int j = 0; j < temp.size(); j++) {
                ar[ind] = temp[j]; ind += 1;
            }
        } else {
            ar[ind] = ar[n - 1]; ind += 1;
        }
        return ind;
    }
};