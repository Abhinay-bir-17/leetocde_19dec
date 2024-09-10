class Solution {
public:
    int itpow(int a, int b) {
        int ans = 1;
        int temp = b;
        while (temp) {
            if (temp & 1) {
                ans = ans * a;
            }
            a = a * a;
            temp = temp >> 1;
        } return ans;
    }
    int maximum69Number (int num) {
        int pos = -1;
        int temp = num; int cnt = 0;
        while (temp) {
            if (temp % 10 == 6)pos = cnt; cnt += 1;
            temp = temp / 10;
        }
        if (pos == -1)return num;
        cnt = 0;
        temp = num;
        num = 0;
        while (temp) {
            int rem;
            if (cnt == pos) {
                rem = 9;
            } else {
                rem = temp % 10;

            }
            num = rem * itpow(10, cnt) + (num);
            cnt += 1;
            temp = temp / 10;
        } return num;
    }
};